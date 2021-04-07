#ifndef TYLE
#define TYLE

#include "sample.h"
#include "sample_set.h"
#include "../color/color_map.h"

enum RELATIVE_POSITION {
	rp_UP = 0,
	rp_LEFT,
	rp_DOWN,
	rp_RIGHT
};

const size_t RELPOS_SHIFTS_X[] = {0, (size_t) -1, 0, 1};
const size_t RELPOS_SHIFTS_Y[] = {(size_t) -1, 0, 1, 0};

class wfc_Tyle : public wfc_Sample, public ColorMap {
public:
	wfc_Tyle();
	wfc_Tyle(const size_t width_, const size_t height_);
	wfc_Tyle(const char *file);

	void fill_tyle(wfc_Tyle &tyle, const size_t x, const size_t y) const;

	bool fits(const wfc_Sample *sample, const int rel_pos) const override;
	wfc_SampleSet samplize() const override;
	bool eq_sample(const wfc_Sample *sample) const override;

	wfc_Tyle *rot90 () const;
	wfc_Tyle *refl_hor () const;
	wfc_Tyle *refl_vert() const;

	wfc_SampleSet cut_and_samplize(const size_t n) const;
};

#endif // TYLE