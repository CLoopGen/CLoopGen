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
    for (row = 0; row < height; row++) {
        yq = uq = vq = 0;
        col = 0;
        if (width / 4 > 0) {
            for (; col < width / 4 - 1; col++) {
                encoded[pixel_ptr] = yq -= encoded[pixel_ptr];
                encoded[pixel_ptr + 1] = yq -= encoded[pixel_ptr + 1];
                encoded[pixel_ptr + 2] = yq -= encoded[pixel_ptr + 2];
                encoded[pixel_ptr + 3] = yq -= encoded[pixel_ptr + 3];
                encoded[pixel_ptr + 4] = uq -= encoded[pixel_ptr + 4];
                encoded[pixel_ptr + 5] = vq -= encoded[pixel_ptr + 5];
                pixel_ptr += 6;
            }
            // Final unrolled iteration
            encoded[pixel_ptr] = yq -= encoded[pixel_ptr];
            encoded[pixel_ptr + 1] = yq -= encoded[pixel_ptr + 1];
            encoded[pixel_ptr + 2] = yq -= encoded[pixel_ptr + 2];
            encoded[pixel_ptr + 3] = yq -= encoded[pixel_ptr + 3];
            encoded[pixel_ptr + 4] = uq -= encoded[pixel_ptr + 4];
            encoded[pixel_ptr + 5] = vq -= encoded[pixel_ptr + 5];
            pixel_ptr += 6;
        }
    }
}
