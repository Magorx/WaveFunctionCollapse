#ifndef SAMPLE_SET
#define SAMPLE_SET

#include <cstdlib>
#include <vector>

#include "sample.h"

class wfc_SampleSet {
public:
	std::vector<const wfc_Sample*> samples;
	char *fitmask;
	size_t rel_pos_amount;

	wfc_SampleSet(const size_t rel_pos_amount_ = 0);

	void add_sample(const wfc_Sample *sample);
	bool rebuild_fitmask();
	char fits(const size_t first, const size_t second, const int rel_pos) const;
};

#endif // SAMPLE_SET