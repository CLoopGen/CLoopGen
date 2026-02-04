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
        yq = uq = vq = 0;
        for (col = 0; col < width / 4; col++) {
            int base = pixel_ptr;
            encoded[base]     = yq -= (encoded[base] >> 1);
            encoded[base + 1] = yq -= (encoded[base + 1] >> 1);
            encoded[base + 2] = yq -= (encoded[base + 2] >> 1);
            encoded[base + 3] = yq -= (encoded[base + 3] >> 1);
            if (row + 1 < height) {
                encoded[base + 4] = uq -= (encoded[base + 4] >> 1);
                encoded[base + 5] = uq -= (encoded[base + 5] >> 1);
                encoded[base + 6] = vq -= (encoded[base + 6] >> 1);
                encoded[base + 7] = vq -= (encoded[base + 7] >> 1);
            }
            pixel_ptr += 8;
        }
        if (row + 1 < height) {
            yq = uq = vq = 0;
            for (col = 0; col < width / 4; col++) {
                encoded[pixel_ptr] = yq -= encoded[pixel_ptr];
                encoded[pixel_ptr + 1] = yq -= encoded[pixel_ptr + 1];
                encoded[pixel_ptr + 2] = yq -= encoded[pixel_ptr + 2];
                encoded[pixel_ptr + 3] = yq -= encoded[pixel_ptr + 3];
                encoded[pixel_ptr + 4] = uq -= encoded[pixel_ptr + 4];
                encoded[pixel_ptr + 5] = uq -= encoded[pixel_ptr + 5];
                encoded[pixel_ptr + 6] = vq -= encoded[pixel_ptr + 6];
                encoded[pixel_ptr + 7] = vq -= encoded[pixel_ptr + 7];
                pixel_ptr += 8;
            }
        }
    }
}
