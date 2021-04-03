#ifndef SAMPLE
#define SAMPLE

class wfc_SampleSet;

class wfc_Sample {
public:
	virtual bool fits(const wfc_Sample *sample, const int rel_pos) const = 0;
	virtual wfc_SampleSet samplize() const = 0;
	virtual bool eq_sample(const wfc_Sample *sample) const = 0;
};

#endif // SAMPLE