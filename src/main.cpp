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
	"pipe_empty.png"
};

const size_t SAMPLE_W = 7;
const size_t SAMPLE_H = 7;

const size_t WFC_W = 20;
const size_t WFC_H = 20;

const size_t SCALE = 7;

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
	for (int i = 0; i < filenames.size(); ++i) {
		sset.add_sample_set(tyles[i]->samplize());
	}
	printf("samples: %lu\n", sset.size());

	WaveFunctionCollapser wfc(WFC_W, WFC_H, sset);

// ============================================================================

	sf::Texture texture;
    texture.create(SCR_W, SCR_H);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale({SCALE, SCALE});
    sf::RenderWindow window(sf::VideoMode(SCR_W, SCR_H), "WFC");

	while (window.isOpen()) {
		// TIMER_START();
		while (!wfc.collapse());
		// TIMER_END_AND_PRINT();
		wfc.generate_image(SAMPLE_W, SAMPLE_H);

		sf::Event event;
		while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
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