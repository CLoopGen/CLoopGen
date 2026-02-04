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
        for (col = 0; col < width / 4; col++) {
            if (col == 0) {
                yq = uq = vq = 0;
            }
            int base = pixel_ptr + col * 6;
            encoded[base] = yq -= encoded[base];
            encoded[base + 1] = yq -= encoded[base + 1];
            encoded[base + 2] = yq -= encoded[base + 2];
            encoded[base + 3] = yq -= encoded[base + 3];
            encoded[base + 4] = uq -= encoded[base + 4];
            encoded[base + 5] = vq -= encoded[base + 5];
        }
        pixel_ptr += (width / 4) * 6;
    }
}
