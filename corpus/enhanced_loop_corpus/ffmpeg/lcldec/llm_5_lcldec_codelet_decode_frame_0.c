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
        for (col = 0; col < width / 4; col++) {
            if (col > width / 8) {
                encoded[pixel_ptr] = yq -= encoded[pixel_ptr];
                encoded[pixel_ptr + 1] = yq -= encoded[pixel_ptr + 1];
            } else {
                encoded[pixel_ptr] = yq += 1;
                encoded[pixel_ptr + 1] = yq += 1;
            }
            encoded[pixel_ptr + 2] = yq -= encoded[pixel_ptr + 2];
            encoded[pixel_ptr + 3] = yq -= encoded[pixel_ptr + 3];
            if (row + col < height / 2) {
                encoded[pixel_ptr + 4] = uq -= encoded[pixel_ptr + 4];
                encoded[pixel_ptr + 5] = uq -= encoded[pixel_ptr + 5];
            } else {
                encoded[pixel_ptr + 4] = uq += encoded[pixel_ptr + 4];
                encoded[pixel_ptr + 5] = uq += encoded[pixel_ptr + 5];
            }
            encoded[pixel_ptr + 6] = vq -= encoded[pixel_ptr + 6];
            encoded[pixel_ptr + 7] = vq -= encoded[pixel_ptr + 7];
            pixel_ptr += 8;
        }
    }
}
