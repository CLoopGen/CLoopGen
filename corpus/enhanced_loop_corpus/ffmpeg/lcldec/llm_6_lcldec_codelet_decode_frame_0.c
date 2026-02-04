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
        unsigned char temp_y = encoded[pixel_ptr];
        encoded[pixel_ptr] = yq - temp_y;
        yq = encoded[pixel_ptr];

        temp_y = encoded[pixel_ptr + 1];
        encoded[pixel_ptr + 1] = yq - temp_y;
        yq = encoded[pixel_ptr + 1];

        temp_y = encoded[pixel_ptr + 2];
        encoded[pixel_ptr + 2] = yq - temp_y;
        yq = encoded[pixel_ptr + 2];

        temp_y = encoded[pixel_ptr + 3];
        encoded[pixel_ptr + 3] = yq - temp_y;
        yq = encoded[pixel_ptr + 3];

        unsigned char temp_u = encoded[pixel_ptr + 4];
        encoded[pixel_ptr + 4] = uq - temp_u;
        uq = encoded[pixel_ptr + 4];

        temp_u = encoded[pixel_ptr + 5];
        encoded[pixel_ptr + 5] = uq - temp_u;
        uq = encoded[pixel_ptr + 5];

        unsigned char temp_v = encoded[pixel_ptr + 6];
        encoded[pixel_ptr + 6] = vq - temp_v;
        vq = encoded[pixel_ptr + 6];

        temp_v = encoded[pixel_ptr + 7];
        encoded[pixel_ptr + 7] = vq - temp_v;
        vq = encoded[pixel_ptr + 7];

        pixel_ptr += 8;
    }
}
}
