#ifndef SAMPLE_SET
#define SAMPLE_SET

#include <cstdio>
#include <cstdlib>
#include <vector>

#include "sample.h"

class wfc_SampleSet {
public:
	std::vector<const wfc_Sample*> samples;
	char *fitmask;
	size_t rel_pos_amount;

	wfc_SampleSet(const size_t rel_pos_amount_ = 0);
	wfc_SampleSet(const wfc_SampleSet &other);

	inline void add_sample(const wfc_Sample *sample) {
		samples.push_back(sample);
	}

	void add_sample_set(const wfc_SampleSet &sset);
	bool reserve_fitmask(const size_t ssize);
	bool rebuild_fitmask();
	void shrink();
	char fits(const size_t first, const size_t second, const int rel_pos) const;

	size_t get_index(const wfc_Sample *sample);
	void update_fitmask(const size_t first, const size_t second, const int rel_pos, const char fitting);

	size_t size() const;
	
};

#endif // SAMPLE_SET