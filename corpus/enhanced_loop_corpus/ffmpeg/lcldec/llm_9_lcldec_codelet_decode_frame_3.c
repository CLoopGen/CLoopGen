#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int pixel_ptr;
extern int row;
extern int col;
extern unsigned char *encoded;
extern int width;
extern int height;
extern unsigned char yq;
extern unsigned char uq;
extern unsigned char vq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (row = 0; row < height; row += 2) {
    pixel_ptr = row * width * 2;
    yq = uq = vq = 0;
    for (col = 0; col < width / 2; col++) {
        encoded[pixel_ptr] = yq -= encoded[pixel_ptr] + 1;
        encoded[pixel_ptr + 1] = yq -= encoded[pixel_ptr + 1] + 2;
        encoded[pixel_ptr + 2] = uq -= encoded[pixel_ptr + 2] + 1;
        encoded[pixel_ptr + 3] = vq -= encoded[pixel_ptr + 3] + 1;
        pixel_ptr += 4;
    }
    if (row + 1 < height) {
        pixel_ptr = (row + 1) * width * 2;
        yq = uq = vq = 0;
        for (col = 0; col < width / 2; col++) {
            encoded[pixel_ptr] = yq -= encoded[pixel_ptr] - 1;
            encoded[pixel_ptr + 1] = yq -= encoded[pixel_ptr + 1] - 2;
            encoded[pixel_ptr + 2] = uq -= encoded[pixel_ptr + 2] - 1;
            encoded[pixel_ptr + 3] = vq -= encoded[pixel_ptr + 3] - 1;
            pixel_ptr += 4;
        }
    }
}
}
