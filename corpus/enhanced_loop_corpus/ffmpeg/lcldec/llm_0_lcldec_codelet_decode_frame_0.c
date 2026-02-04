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
            for (int offset = 0; offset < 4; offset++) {
                encoded[pixel_ptr + offset] = yq -= encoded[pixel_ptr + offset];
            }
            encoded[pixel_ptr + 4] = uq -= encoded[pixel_ptr + 4];
            encoded[pixel_ptr + 5] = uq -= encoded[pixel_ptr + 5];
            encoded[pixel_ptr + 6] = vq -= encoded[pixel_ptr + 6];
            encoded[pixel_ptr + 7] = vq -= encoded[pixel_ptr + 7];
            pixel_ptr += 8;
        }
    }
}
