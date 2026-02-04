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
for (row = 0; row < height / 4; row++) {
    pixel_ptr = row * width * 3;
    yq = y1q = uq = vq = 0;
    for (col = 0; col < width / 4; col++) {
        encoded[pixel_ptr]     = yq -= encoded[pixel_ptr];
        encoded[pixel_ptr + 1] = yq -= encoded[pixel_ptr + 1];
        encoded[pixel_ptr + 2] = y1q -= encoded[pixel_ptr + 2];
        encoded[pixel_ptr + 3] = y1q -= encoded[pixel_ptr + 3];
        encoded[pixel_ptr + 4] = uq -= encoded[pixel_ptr + 4];
        encoded[pixel_ptr + 5] = vq -= encoded[pixel_ptr + 5];

        encoded[pixel_ptr + 6]     = yq -= encoded[pixel_ptr + 6];
        encoded[pixel_ptr + 7]     = yq -= encoded[pixel_ptr + 7];
        encoded[pixel_ptr + 8]     = y1q -= encoded[pixel_ptr + 8];
        encoded[pixel_ptr + 9]     = y1q -= encoded[pixel_ptr + 9];
        encoded[pixel_ptr + 10]    = uq -= encoded[pixel_ptr + 10];
        encoded[pixel_ptr + 11]    = vq -= encoded[pixel_ptr + 11];

        encoded[pixel_ptr + 12]    = yq -= encoded[pixel_ptr + 12];
        encoded[pixel_ptr + 13]    = yq -= encoded[pixel_ptr + 13];
        encoded[pixel_ptr + 14]    = y1q -= encoded[pixel_ptr + 14];
        encoded[pixel_ptr + 15]    = y1q -= encoded[pixel_ptr + 15];
        encoded[pixel_ptr + 16]    = uq -= encoded[pixel_ptr + 16];
        encoded[pixel_ptr + 17]    = vq -= encoded[pixel_ptr + 17];

        encoded[pixel_ptr + 18]    = yq -= encoded[pixel_ptr + 18];
        encoded[pixel_ptr + 19]    = yq -= encoded[pixel_ptr + 19];
        encoded[pixel_ptr + 20]    = y1q -= encoded[pixel_ptr + 20];
        encoded[pixel_ptr + 21]    = y1q -= encoded[pixel_ptr + 21];
        encoded[pixel_ptr + 22]    = uq -= encoded[pixel_ptr + 22];
        encoded[pixel_ptr + 23]    = vq -= encoded[pixel_ptr + 23];

        pixel_ptr += 24;
    }
}
}
