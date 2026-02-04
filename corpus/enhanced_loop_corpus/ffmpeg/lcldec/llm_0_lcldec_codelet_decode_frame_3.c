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
        col = 0;
        while (col < width / 2) {
            encoded[pixel_ptr] = yq -= encoded[pixel_ptr];
            encoded[pixel_ptr + 1] = yq -= encoded[pixel_ptr + 1];
            encoded[pixel_ptr + 2] = uq -= encoded[pixel_ptr + 2];
            encoded[pixel_ptr + 3] = vq -= encoded[pixel_ptr + 3];
            pixel_ptr += 4;
            col++;
        }
    }
}
