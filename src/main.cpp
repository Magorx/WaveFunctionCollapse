#include <cstdio>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <vector>

#include "wfc.h"
#include "utils/timer.h"

std::vector<const char*> filenames = {
	"pipe_straight.png",
	"pipe_cross.png",
	"pipe_angle.png",
	"pipe_empty.png",
	"pipe_water.png",
	"pipe_water_T.png",
	"pipe_water_LT.png",
	"pipe_water_ss.png",
	//"pipe_water_end.png",
	"pipe_and_water_L.png",
	"pipe_and_water_s.png",
	"pipe_water_l.png",
	//"pipe_and_water_l.png",
	"pipe_water_L.png",
	"pipe_water_LL.png",
};

// std::vector<const char*> filenames = {
// 	//"world/grass_1.png",
// 	"world/road_l.png",
// 	"world/road_L.png",
// 	"world/road_X.png",
// 	"world/grass.png",
// 	"world/water.png",
// 	"world/water_grass.png",
// 	"world/water_grass_L.png",
// 	"world/water_road.png",
// 	"world/water_road_end.png",
// 	"world/water_road_L.png",
// 	"world/water_road_L_2.png",
// 	//"world/water_road_l.png",
// 	"world/water_road_T.png",
// };

enum MODES {
	m_TILES,
	m_PIC,
};

const MODES MODE = m_TILES;

const size_t SAMPLE_SIZE = 7;

const size_t SAMPLE_W = SAMPLE_SIZE;
const size_t SAMPLE_H = SAMPLE_SIZE;

const size_t WFC_W = 30;
const size_t WFC_H = 30;

const size_t SCALE = 4;

const size_t SCR_W = WFC_W * SAMPLE_W * SCALE;
const size_t SCR_H = WFC_H * SAMPLE_H * SCALE;

const size_t RELPOS_CNT = 4;

int main() {
	srand(time(NULL));

	wfc_SampleSet sset(RELPOS_CNT);

	if (MODE == m_TILES) {
		wfc_Tyle **tyles = (wfc_Tyle**) calloc(filenames.size(), sizeof(wfc_Tyle**));
		for (int i = 0; i < filenames.size(); ++i) {
			tyles[i] = new wfc_Tyle(filenames[i]);
		}

		for (int i = 0; i < filenames.size(); ++i) {
			sset.add_sample_set(tyles[i]->samplize());
		}
		sset.rebuild_fitmask();
	} else if (MODE == m_PIC) {
		wfc_Tyle t("bricks.png");
		sset = t.cut_and_samplize(SAMPLE_SIZE);
		//sset.shrink();
	}

	printf("samples: %lu\n", sset.size());
	if (!sset.size()) {
		printf("aborting...\n");
		return 0;
	}

	WaveFunctionCollapser wfc(WFC_W, WFC_H, sset);

	for (int i = 0; i < RELPOS_CNT; ++i) {
		printf("dir [%d]\n", i);
		for (int j = 0; j < sset.size(); ++j) {
			for (int k = 0; k < sset.size(); ++k) {
				printf("[%d] + [%d] = %c\n", j, k, wfc.sample_set.fits(j, k, i) ? 'Y' : 'N');
			}
			printf("\n");
		}
	}

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
		//while (!wfc.collapse(&tsw)) {
		while (!wfc.collapse()) {
			++cnt;
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