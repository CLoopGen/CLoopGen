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
    for (row = 0; row < height / 2; row++) {
        for (col = 0; col < width / 2; col++) {
            pixel_ptr = row * width * 3 + col * 6;
            yq = y1q = uq = vq = 0;
            encoded[pixel_ptr] = yq -= encoded[pixel_ptr];
            encoded[pixel_ptr + 1] = yq -= encoded[pixel_ptr + 1];
            encoded[pixel_ptr + 2] = y1q -= encoded[pixel_ptr + 2];
            encoded[pixel_ptr + 3] = y1q -= encoded[pixel_ptr + 3];
            encoded[pixel_ptr + 4] = uq -= encoded[pixel_ptr + 4];
            encoded[pixel_ptr + 5] = vq -= encoded[pixel_ptr + 5];
        }
    }
}
