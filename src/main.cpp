#include <cstdio>
#include <cstdlib>

#include "sample/tyle.h"
#include "sample/sample_set.h"

int main() {
	wfc_Tyle t1("1.png");
	wfc_Tyle t2("2.png");
	wfc_Tyle t3("3.png");
	wfc_Tyle t4("4.png");

	wfc_SampleSet sset(4);
	sset.add_sample(&t1);
	sset.add_sample(&t2);
	sset.add_sample(&t3);
	sset.add_sample(&t4);
	sset.rebuild_fitmask();

	for (int rp = 0; rp < 4; ++rp) {
		printf("dir %d)\n", rp);
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				printf("[%d] [%d] = %c\n", i, j, sset.fits(i, j, rp) ? 'Y' : 'N');
			}
		}
	}

	printf("doned\n");
	return 0;
}