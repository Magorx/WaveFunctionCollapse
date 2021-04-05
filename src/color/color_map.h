#ifndef COLOR_MAP_PACK4
#define COLOR_MAP_PACK4

#include <cstdlib>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "color.h"

class ColorMap {
public:
	size_t   width;
	size_t   height;
	ARGB *data;

	// ColorMap           (const ColorMap& other) = delete;
	// ColorMap& operator=(const ColorMap& other) = delete;

	ColorMap();
	ColorMap(const size_t width_, const size_t height_);
	ColorMap(const char *file);

	void rebuild(const size_t width_, const size_t height_);

	ARGB *operator[](const size_t i);
	const ARGB *operator[](const size_t i) const;

	void crop_rectangle(size_t &x0, size_t &y0, size_t &x1, size_t &y1) const;

	void superimpose(const ColorMap &cmap, size_t x0, size_t y0);
	void superimpose_divided(const ColorMap &cmap, size_t x0, size_t y0, float divisor);
	// void superimpose_alpha_intr(const ColorMap &cmap, size_t x0, size_t y0);

	void flush_to_texture(sf::Texture &texture);
};

#endif // COLOR_MAP_PACK4