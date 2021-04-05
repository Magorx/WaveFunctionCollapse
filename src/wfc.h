#ifndef WAVE_FUNCTION_COLLAPSE
#define WAVE_FUNCTION_COLLAPSE

#include "sample/collection_samples.h"
#include "sample/sample_set.h"
#include "color/color_map.h"

#include <set>
#include <queue>

#include <SFML/Graphics.hpp>
struct TSW {
	sf::Texture *texture;
	sf::Sprite *sprite;
	sf::RenderWindow *window;
	size_t sample_size;
};

class WaveFunctionCollapser {
public:
	size_t width;
	size_t height;
	size_t *final_index_map;
	std::set<size_t> *index_map;
	wfc_SampleSet sample_set;
	ColorMap cmap;

	WaveFunctionCollapser(size_t width_, size_t height_, wfc_SampleSet sample_set_);
	bool collapse(TSW *tws = nullptr);

	void generate_image(const size_t sample_w, const size_t sample_h);
	void generate_mean_image(const size_t sample_w, const size_t sample_h);

	inline bool check_coord(const size_t x, const size_t y) const {
		return x < width && y < height;
	}

	inline bool check_coord(const size_t coord) const {
		return coord < width * height;
	}
};

#endif // WAVE_FUNCTION_COLLAPSE