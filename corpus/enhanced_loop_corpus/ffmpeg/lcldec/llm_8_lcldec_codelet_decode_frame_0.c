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
        for (col = 0; col < width / 8; col++) {
            encoded[pixel_ptr] = yq -= encoded[pixel_ptr] + 1;
            encoded[pixel_ptr + 1] = yq -= encoded[pixel_ptr + 1] + 1;
            encoded[pixel_ptr + 2] = yq -= encoded[pixel_ptr + 2] + 1;
            encoded[pixel_ptr + 3] = yq -= encoded[pixel_ptr + 3] + 1;
            encoded[pixel_ptr + 4] = uq -= encoded[pixel_ptr + 4] + 1;
            encoded[pixel_ptr + 5] = uq -= encoded[pixel_ptr + 5] + 1;
            encoded[pixel_ptr + 6] = vq -= encoded[pixel_ptr + 6] + 1;
            encoded[pixel_ptr + 7] = vq -= encoded[pixel_ptr + 7] + 1;
            pixel_ptr += 8;
        }
    }
}
