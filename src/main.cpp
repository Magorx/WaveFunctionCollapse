#include <cstdio>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <vector>

#include "wfc.h"
#include "utils/timer.h"

// std::vector<const char*> filenames = {
// 	"pipe_straight.png",
// 	"pipe_cross.png",
// 	"pipe_angle.png",
// 	"pipe_empty.png"
// 	"pipe_pump.png"
// };

std::vector<const char*> filenames = {
	"pipe_straight.png",
	"pipe_cross.png",
	"pipe_angle.png",
	"pipe_empty.png"
};

const size_t SAMPLE_SIZE = 7;

const size_t SAMPLE_W = SAMPLE_SIZE;
const size_t SAMPLE_H = SAMPLE_SIZE;

const size_t WFC_W = 25;
const size_t WFC_H = 25;

const size_t SCALE = 5;

const size_t SCR_W = WFC_W * SAMPLE_W * SCALE;
const size_t SCR_H = WFC_H * SAMPLE_H * SCALE;

const size_t RELPOS_CNT = 4;

int main() {
	srand(time(NULL));

	wfc_Tyle **tyles = (wfc_Tyle**) calloc(filenames.size(), sizeof(wfc_Tyle**));
	for (int i = 0; i < filenames.size(); ++i) {
		tyles[i] = new wfc_Tyle(filenames[i]);
	}

	wfc_SampleSet sset(RELPOS_CNT);
	// wfc_Tyle t("bricks.png");
	// sset.add_sample_set(t.cut_and_samplize(SAMPLE_SIZE));

	for (int i = 0; i < filenames.size(); ++i) {
		sset.add_sample_set(tyles[i]->samplize());
	}

	sset.rebuild_fitmask();

	printf("samples: %lu\n", sset.size());

	// for (int i = 0; i < RELPOS_CNT; ++i) {
	// 	printf("dir [%d]\n", i);
	// 	for (int j = 0; j < sset.size(); ++j) {
	// 		for (int k = 0; k < sset.size(); ++k) {
	// 			printf("[%d] + [%d] = %c\n", j, k, sset.fits(j, k, i) ? 'Y' : 'N');
	// 		}
	// 		printf("\n");
	// 	}
	// }

	WaveFunctionCollapser wfc(WFC_W, WFC_H, sset);

// ============================================================================

	sf::Texture texture;
    texture.create(SCR_W, SCR_H);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale({SCALE, SCALE});
    sf::RenderWindow window(sf::VideoMode(SCR_W, SCR_H), "WFC");

    TSW tsw = {&texture, &sprite, &window, SAMPLE_SIZE};

	while (window.isOpen()) {
		// TIMER_START();
		int cnt = 0;
		while (!wfc.collapse(&tsw)) {
			++cnt;
			sf::sleep(sf::seconds(2));
			if (cnt % 100 == 0) {
				printf("%d...\n", cnt);
			}
		}
		wfc.generate_image(SAMPLE_W, SAMPLE_H);
		if (!window.isOpen()) {
        	break;
        }
		// TIMER_END_AND_PRINT();

		sf::Event event;
		while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }
        }

        window.clear();
        wfc.cmap.flush_to_texture(texture);
        window.draw(sprite);
        window.display();

        sf::sleep(sf::seconds(1));
    }

// ============================================================================

	printf("doned\n");
	return 0;
}