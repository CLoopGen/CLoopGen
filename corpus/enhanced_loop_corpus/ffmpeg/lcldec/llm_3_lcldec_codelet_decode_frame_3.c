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
            int idxs[4] = {pixel_ptr, pixel_ptr + 1, pixel_ptr + 2, pixel_ptr + 3};
            encoded[idxs[0]] = yq -= encoded[idxs[0]];
            encoded[idxs[1]] = yq -= encoded[idxs[1]];
            encoded[idxs[2]] = uq -= encoded[idxs[2]];
            encoded[idxs[3]] = vq -= encoded[idxs[3]];
            pixel_ptr += 4;
        }
    }
}
