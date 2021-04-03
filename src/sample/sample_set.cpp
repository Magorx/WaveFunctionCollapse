#include "sample_set.h"

wfc_SampleSet::wfc_SampleSet(const size_t rel_pos_amount_):
rel_pos_amount(rel_pos_amount_),
fitmask(nullptr)
{}

bool wfc_SampleSet::rebuild_fitmask() {
	size_t cnt = samples.size();

	fitmask = (char*) calloc(cnt * cnt * rel_pos_amount, sizeof(wfc_Sample*));
	if (!fitmask) {
		return false;
	}

	for (size_t i = 0; i < cnt; ++i) {
		for (size_t j = 0; j < cnt; ++j) {
			for (size_t rel_pos = 0; rel_pos < rel_pos_amount; ++rel_pos) {
				fitmask[i * cnt  * rel_pos_amount + j * rel_pos_amount + rel_pos] = samples[i]->fits(samples[j], rel_pos);
			}
		}
	}

	return true;
}

void wfc_SampleSet::add_sample_set(const wfc_SampleSet &sset) {
	for (auto sample : sset.samples) {
		bool to_add = true;
		for (auto s : samples) {
			if (s->eq_sample(sample)) {
				to_add = false;
				break;
			}
		}
		if (to_add) {
			add_sample(sample);
		}
	}
}

char wfc_SampleSet::fits(const size_t first, const size_t second, const int rel_pos) const {
	size_t cnt = samples.size();
	return fitmask[first * cnt * rel_pos_amount + second * rel_pos_amount + rel_pos];
}

size_t wfc_SampleSet::size() const {
	return samples.size();
}
