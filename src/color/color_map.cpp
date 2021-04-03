#include "color_map.h"

ColorMap::ColorMap():
width(0),
height(0),
data(nullptr)
{}

ColorMap::ColorMap(const size_t width_, const size_t height_) {
	width = width_;
	height = height_;
	data = (ARGB*) calloc(width * height, sizeof(ARGB));

	if (!data) {
		fprintf(stderr, "[ERR]<ColorMap>: data is not allocated in ctor\n");
	}
}

void ColorMap::rebuild(const size_t width_, const size_t height_) {
	width = width_;
	height = height_;
	data = (ARGB*) calloc(width * height, sizeof(ARGB));

	if (!data) {
		fprintf(stderr, "[ERR]<ColorMap>: data is not allocated in rebuild\n");
	}
}

ColorMap::ColorMap(const char *file) {
	sf::Image img;
	img.loadFromFile(file);

	auto size = img.getSize();
	size_t Width = size.x;
	size_t Height = size.y;
	rebuild(Width, Height);

	for (size_t y = 0; y < height; ++y) {
		for (size_t x = 0; x < width; ++x) {
			sf::Color color = img.getPixel(x, y);
			data[y * width + x] = {color.r, color.g, color.b, color.a};
		}
	}
}

void ColorMap::flush_to_texture(sf::Texture &texture) {
	sf::Image image;
	image.create(width, height);

	for (size_t y = 0; y < height; ++y) {
		for (size_t x = 0; x < width; ++x) {
			ARGB color = data[y * width + x];
			sf::Color sf_color(color.r, color.g, color.b);
			image.setPixel(x, y, sf_color);
		}
	}

	texture.loadFromImage(image);
}

ARGB *ColorMap::operator[](const size_t i) {
	return data + i * width;
}

const ARGB *ColorMap::operator[](const size_t i) const {
	return data + i * width;
}

void ColorMap::crop_rectangle(size_t &x0, size_t &y0, size_t &x1, size_t &y1) const {
	x0 = std::max(x0, 0lu);
	y0 = std::max(y0, 0lu);
	x1 = std::min(x1, width);
	y1 = std::min(y1, height);

	x0 = std::min(x0, width);
	y0 = std::min(y0, height);
	x1 = std::max(x1, 0lu);
	y1 = std::max(y1, 0lu);

	if (x0 > x1) {
		std::swap(x0, x1);
	}
	if (y0 > y1) {
		std::swap(y0, y1);
	}
}

void ColorMap::superimpose(const ColorMap &cmap, size_t x0, size_t y0) {
	size_t x1 = x0 + cmap.width;
	size_t y1 = y0 + cmap.height;
	crop_rectangle(x0, y0, x1, y1);

	for (size_t y = y0, yy = 0; y < y1; ++y, ++yy) {
		for (size_t x = x0, xx = 0; x < x1; ++x, ++xx) {
			ARGB c1 = data[y * width + x];
			ARGB c2 = cmap[yy][xx];
			data[y * width + x] = c2;
		}
	}
}

// void ColorMap::superimpose_alpha_intr(const ColorMap &cmap, size_t x0, size_t y0) {
// 	if (!is_valid() || !cmap.is_valid()) {
// 		printf("[ERR]<superimpose>: bad imagies provided\n");
// 		return;
// 	}
	
// 	x0 = force_align_4(x0);
// 	size_t x1 = x0 + cmap.width ;
// 	size_t y1 = y0 + cmap.height;
// 	crop_rectangle(x0, y0, x1, y1);

// 	const unsigned char ZZ = 0x80;

// 	m256 msk_prep_for_mix (	ZZ, ZZ, ZZ, ZZ, ZZ, ZZ, ZZ, ZZ,
//                     		23, 21, 19, 17, 31, 29, 27, 25,
//                     		ZZ, ZZ, ZZ, ZZ, ZZ, ZZ, ZZ, ZZ,
//                     		 7,  5,  3,  1, 15, 13, 11,  9 );

// 	m256 msk_alpha        (	ZZ, 24, ZZ, 24, ZZ, 24, ZZ, 24,
// 							ZZ, 16, ZZ, 16, ZZ, 16, ZZ, 16,
// 							ZZ,  8, ZZ,  8, ZZ,  8, ZZ,  8,
// 							ZZ,  0, ZZ,  0, ZZ,  0, ZZ,  0 );

//     m256 max_alpha((int16_t) 255);

// 	for (size_t y = y0, yy = 0; y < y1; ++y, ++yy) {
// 		for (size_t x = x0, xx = 0; x < x1; x += 4, xx += 4) {
// 			int4 fg_pxls((__m128i*)(cmap.data + yy * cmap.width + xx));
// 			int4 bg_pxls((__m128i*)(data + y * width + x));

// 			m256 fg(fg_pxls.extend_zeroes_256_epi16());
// 			m256 bg(bg_pxls.extend_zeroes_256_epi16());

// 			m256 alpha_fg = fg.shuffle_256_epi8(msk_alpha);
//             m256 alpha_bg = max_alpha.sub_256_epi16(alpha_fg);

// 			fg = fg.mul_256_epi16(alpha_fg);
// 			bg = bg.mul_256_epi16(alpha_bg);

// 			m256 result_256 = fg.add_256_epi16(bg);
// 			result_256 = result_256.shuffle_256_epi8(msk_prep_for_mix);

//             int4 result = join_lh(result_256.mint4[1], result_256.mint4[0]);

//             result.mem_store(data + y * width + x);
// 		}
// 	}

// }
