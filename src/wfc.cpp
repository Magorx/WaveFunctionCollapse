#include "wfc.h"

WaveFunctionCollapser::WaveFunctionCollapser(size_t width_, size_t height_, wfc_SampleSet sample_set_):
width(width_),
height(height_),
final_index_map((size_t*) calloc(width_ * height_, sizeof(size_t))),
index_map(new std::set<size_t>[width_ * height_]),
sample_set(sample_set_)
{
	if (!final_index_map || !index_map) {
		printf("[ERR]<WFC>: bad pts in ctor\n");
		return;
	}
}

struct wfc_WeightedPair {
	size_t variants_left;
	size_t coord; 
};

bool operator<(const wfc_WeightedPair &a, const wfc_WeightedPair &b) {
	if (a.variants_left < b.variants_left) {
		return true;
	} else if (a.variants_left > b.variants_left) {
		return false;
	} else {
		return a.coord < b.coord;
	}
}

bool WaveFunctionCollapser::collapse(TSW *tsw) {
	// printf("collapsing...\n");
	size_t square = width * height;
	size_t s_cnt = sample_set.size();

	for (size_t i = 0; i < square; ++i) {
		final_index_map[i] = (size_t) -1;

		std::set<size_t> &s = index_map[i];
		s.clear();
		for (size_t j = 0; j < s_cnt; ++j) {
			s.insert(j);
		}
	}

	size_t init_coord = rand() % square;
	std::set<wfc_WeightedPair> q;

	q.insert({index_map[init_coord].size(), init_coord});
	bool flag = false;
	while (q.size()) {
		wfc_WeightedPair p = *q.begin();
		q.erase(p);

		size_t coord = p.coord;
		std::set<size_t> &s = index_map[coord];
		int roll = rand() % s.size();
		size_t x = *std::next(s.begin(), roll);
		final_index_map[coord] = x;
		s.clear();
		s.insert(x);

		if (tsw) {
			sf::Event event;
			while (tsw->window->pollEvent(event)) {
	            if (event.type == sf::Event::Closed)
	                tsw->window->close();
	        }
	        if (!tsw->window->isOpen()) {
				return true;
			}

			for (int i = 0; i < sample_set.size(); ++i) {
				final_index_map[2 * i] = i;
			}

			generate_mean_image(tsw->sample_size, tsw->sample_size);

			tsw->window->clear();
	        cmap.flush_to_texture(*tsw->texture);
	        tsw->window->draw(*tsw->sprite);
	        tsw->window->display();
	        sf::sleep(sf::seconds(0.001));
		}

		size_t shifts[4] = {(size_t) -width, (size_t) -1, +width, +1};
		for (int rel_pos = 0; rel_pos < 4; ++rel_pos) {
			size_t new_coord = coord + shifts[rel_pos];
			if (!check_coord(new_coord) || final_index_map[new_coord] != (size_t) -1
				|| (rel_pos == 1 && coord % width == 0)
				|| (rel_pos == 3 && coord % width == width - 1)){
				continue;
			}

			std::set<size_t> &new_s = index_map[new_coord];
			if (q.find({new_s.size(), new_coord}) != q.end()) {
				q.erase({new_s.size(), new_coord});
			}
			std::set<size_t> to_remove;
			for (auto sample: new_s) {
				if (!sample_set.fits(x, sample, rel_pos)) {
					to_remove.insert(sample);
				}
			}

			for (auto rem : to_remove) {
				new_s.erase(rem);
			}

			if (new_s.empty()) {
				return false;
			}
			
			q.insert({new_s.size(), new_coord});
		}
	}

	return true;
}

void WaveFunctionCollapser::generate_image(const size_t sample_w, const size_t sample_h) {
	size_t real_w = width  * sample_w;
	size_t real_h = height * sample_h;

	cmap = ColorMap(width * sample_w, height * sample_h);
	for (size_t y = 0; y < height; ++y) {
		for (size_t x = 0; x < width; ++x) {
			size_t coord = y * width + x;
			size_t sample_index = final_index_map[coord];
			if (sample_index == (size_t) -1) {
				continue;
			}

			const wfc_Tyle sample = *(dynamic_cast<const wfc_Tyle*>(sample_set.samples[sample_index]));
			cmap.superimpose(sample, x * sample_w, y * sample_h);
		}
	}
}

void WaveFunctionCollapser::generate_mean_image(const size_t sample_w, const size_t sample_h) {
	size_t real_w = width  * sample_w;
	size_t real_h = height * sample_h;

	cmap = ColorMap(width * sample_w, height * sample_h);
	for (size_t y = 0; y < height; ++y) {
		for (size_t x = 0; x < width; ++x) {
			size_t coord = y * width + x;
			size_t sample_index_cnt = index_map[coord].size();
			wfc_Tyle to_draw(sample_w, sample_h);

			if (final_index_map[coord] < sample_set.size()) {
				const wfc_Tyle sample = *(dynamic_cast<const wfc_Tyle*>(sample_set.samples[final_index_map[coord]]));
				to_draw.superimpose_divided(sample, 0, 0, 1);
			} else {
				for (auto s : index_map[coord]) {
					const wfc_Tyle sample = *(dynamic_cast<const wfc_Tyle*>(sample_set.samples[s]));
					to_draw.superimpose_divided(sample, 0, 0, sample_index_cnt);
				}
			}

			cmap.superimpose(to_draw, x * sample_w, y * sample_h);
		}
	}
}
