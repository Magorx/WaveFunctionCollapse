#include "tyle.h"

wfc_Tyle::wfc_Tyle():
ColorMap()
{}

wfc_Tyle::wfc_Tyle(const size_t width_, const size_t height_):
ColorMap(width_, height_)
{}

wfc_Tyle::wfc_Tyle(const char *file):
ColorMap(file)
{}



bool wfc_Tyle::fits(const wfc_Sample *sample, const int rel_pos) const {
	const wfc_Tyle *tyle = dynamic_cast<const wfc_Tyle*>(sample);

	size_t x1 = 0;
	size_t y1 = 0;
	size_t x2 = 0;
	size_t y2 = 0;

	if (rel_pos == rp_UP) {
		x1 = 0;
		y1 = 0;
		x2 = 0;
		y2 = tyle->height - 1;

		size_t max_width = std::max(width, tyle->width);
		for (int i = 0; i < max_width; ++i, ++x1, ++x2) {
			if ((*tyle)[y2][x2].i != (*this)[y1][x1].i) {
				return false;
			}
		}
	} else if (rel_pos == rp_DOWN) {
		x1 = 0;
		y1 = height - 1;
		x2 = 0;
		y2 = 0;

		size_t max_width = std::max(width, tyle->width);
		for (int i = 0; i < max_width; ++i, ++x1, ++x2) {
			if ((*tyle)[y2][x2].i != (*this)[y1][x1].i) {
				return false;
			}
		}
	} else if (rel_pos == rp_LEFT) {
		x1 = 0;
		y1 = 0;
		x2 = tyle->width - 1;
		y2 = 0;

		size_t max_height = std::max(height, tyle->height);
		for (int i = 0; i < max_height; ++i, ++y1, ++y2) {
			if ((*tyle)[y2][x2].i != (*this)[y1][x1].i) {
				return false;
			}
		}
	} else if (rel_pos == rp_RIGHT) {
		x1 = width - 1;
		y1 = 0;
		x2 = 0;
		y2 = 0;

		size_t max_height = std::max(height, tyle->height);
		for (int i = 0; i < max_height; ++i, ++y1, ++y2) {
			if ((*tyle)[y2][x2].i != (*this)[y1][x1].i) {
				return false;
			}
		}
	} else {
		printf("[ERR]<fits>: bad rel_pos\n");
		return false;
	}

	return true;
}

bool wfc_Tyle::eq_sample(const wfc_Sample *sample) const {
	const wfc_Tyle *tyle = dynamic_cast<const wfc_Tyle*>(sample);

	if (tyle->width != width || tyle->height != height) {
		return false;
	}

	size_t square = width * height;
	for (size_t i = 0; i < square; ++i) {
		if (data[i].i != tyle->data[i].i) {
			return false;
		}
	}

	return true;
}

wfc_SampleSet wfc_Tyle::samplize() const {
	wfc_SampleSet ret;
	wfc_Tyle *r90  = this->rot90();
	wfc_Tyle *r180 = r90 ->rot90();
	wfc_Tyle *r270 = r180->rot90();

	ret.add_sample(this);
	ret.add_sample(r90);
	ret.add_sample(r180);
	ret.add_sample(r270);
	ret.add_sample(refl_hor());
	ret.add_sample(refl_vert());
	return ret;
}

wfc_Tyle *wfc_Tyle::rot90 () const {
	wfc_Tyle *ret = new wfc_Tyle(height, width);
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			(*ret)[width - 1 - j][i] = (*this)[i][j];
		}
	}

	return ret;
}

wfc_Tyle *wfc_Tyle::refl_hor () const {
	wfc_Tyle *ret = new wfc_Tyle(width, height);
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			(*ret)[height - 1 - i][j] = (*this)[i][j];
		}
	}

	return ret;
}

wfc_Tyle *wfc_Tyle::refl_vert() const {
	wfc_Tyle *ret = new wfc_Tyle(width, height);
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			(*ret)[i][width - 1 - j] = (*this)[i][j];
		}
	}

	return ret;
}

wfc_SampleSet wfc_Tyle::cut_and_samplize(const size_t n) const {
	wfc_SampleSet sset;

	for (size_t i = 0; i < height - n; ++i) {
		for (size_t j = 0; j  < width - n; ++j) {
			wfc_Tyle *tyle = new wfc_Tyle(n, n);
			for (size_t y = 0; y < n; ++y) {
				for (size_t x = 0; x < n; ++x) {
					(*tyle)[y][x] = (*this)[i + y][j + x];
				}
			}

			sset.add_sample(tyle);
			// sset.add_sample_set(tyle->samplize());
		}
	}

	return sset;
}
