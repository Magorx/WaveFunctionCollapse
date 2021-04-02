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

wfc_SampleSet wfc_Tyle::samplize() const {
	return {};
}