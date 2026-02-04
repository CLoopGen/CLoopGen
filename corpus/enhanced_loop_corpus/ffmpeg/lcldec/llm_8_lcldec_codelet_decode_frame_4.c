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
extern unsigned char y1q;
extern unsigned char uq;
extern unsigned char vq;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (row = 0; row < height; row++) {
    pixel_ptr = row * width * 3;
    yq = y1q = uq = vq = 0;
    for (col = 0; col < width; col++) {
        encoded[pixel_ptr] = yq -= encoded[pixel_ptr] >> 1;
        encoded[pixel_ptr + 1] = yq -= encoded[pixel_ptr + 1] >> 1;
        if (col % 2 == 0) {
            encoded[pixel_ptr + 2] = y1q -= encoded[pixel_ptr + 2] >> 1;
            encoded[pixel_ptr + 3] = y1q -= encoded[pixel_ptr + 3] >> 1;
            encoded[pixel_ptr + 4] = uq -= encoded[pixel_ptr + 4] >> 1;
            encoded[pixel_ptr + 5] = vq -= encoded[pixel_ptr + 5] >> 1;
            pixel_ptr += 6;
        } else {
            encoded[pixel_ptr + 2] = uq -= encoded[pixel_ptr + 2] >> 1;
            encoded[pixel_ptr + 3] = vq -= encoded[pixel_ptr + 3] >> 1;
            pixel_ptr += 4;
        }
    }
}
}
