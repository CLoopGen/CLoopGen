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
        pixel_ptr = row * width * 2;
        yq = uq = vq = 0;
        for (col = 0; col < width / 2; col++) {
            int base = pixel_ptr + col * 4;
            encoded[base] = yq -= encoded[base];
            encoded[base + 1] = yq -= encoded[base + 1];
            encoded[base + 2] = uq -= encoded[base + 2];
            encoded[base + 3] = vq -= encoded[base + 3];
        }
    }
}
