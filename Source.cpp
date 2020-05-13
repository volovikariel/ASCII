#include <iostream>
#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image_resize.h"

/*Set MAX Size and buffer size in CMD window first*/

int main() {

	int width, height, channelCount;
	unsigned char* image = stbi_load("1280x720.jpg", &width, &height, &channelCount, 3);

	int success = stbir_resize_uint8(image, width, height, 0, image, width, height, 0, channelCount);

	//std::cout << "Image successfully loaded! " << success << std::endl;
	
	unsigned char* image_pixels = new unsigned char[width * height];
	
	unsigned char r;
	unsigned char g;
	unsigned char b;
	
	std::string ASCII = "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$"; // Length 66 but skip 2 and 24
	

	for (size_t i = 0; i < height * width; i++) {
		unsigned char* pixelOffset = &image[i * channelCount];
		r = pixelOffset[0];
		g = pixelOffset[1];
		b = pixelOffset[2];
		// Ignore Alpha for calculations
		float magicNum = floor((((static_cast<int>(r) + static_cast<int>(g) + static_cast<int>(b)) / 3.0f) / 255.0) * 65.0);
	
		char c = ASCII.at(magicNum);

		image_pixels[i] = c;
	}

	for (size_t y = 0; y < height; y++) {
		for (size_t x = 0; x < width; x++) {
			std::cout << image_pixels[x + y*width];
		}
		std::cout << std::endl;
	}
	delete[] image_pixels;
	stbi_image_free(image);
	return 0;
}

//TODO: Convert to RGBA (https://github.com/xeekworx/image/blob/master/image.cpp)