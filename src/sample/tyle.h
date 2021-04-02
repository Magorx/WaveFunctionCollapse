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

class wfc_Tyle : public wfc_Sample, public ColorMap {
public:
	wfc_Tyle();
	wfc_Tyle(const size_t width_, const size_t height_);
	wfc_Tyle(const char *file);

	bool fits(const wfc_Sample *sample, const int rel_pos) const override;
	wfc_SampleSet samplize() const override;
};

#endif // TYLE