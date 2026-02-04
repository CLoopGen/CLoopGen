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



void loop() {
    for (row = 0; row < height; row++) {
        yq = uq = vq = 0;
        for (col = 0; col < width / 4; col++) {
            int base_idx = pixel_ptr + col * 8;
            encoded[base_idx]     = yq -= encoded[base_idx];
            encoded[base_idx + 1] = yq -= encoded[base_idx + 1];
            encoded[base_idx + 2] = yq -= encoded[base_idx + 2];
            encoded[base_idx + 3] = yq -= encoded[base_idx + 3];
            encoded[base_idx + 4] = uq -= encoded[base_idx + 4];
            encoded[base_idx + 5] = uq -= encoded[base_idx + 5];
            encoded[base_idx + 6] = vq -= encoded[base_idx + 6];
            encoded[base_idx + 7] = vq -= encoded[base_idx + 7];
        }
        pixel_ptr += (width / 4) * 8;
    }
}
