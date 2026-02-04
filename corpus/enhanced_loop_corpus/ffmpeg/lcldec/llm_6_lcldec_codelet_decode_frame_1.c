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
            unsigned char temp_y1 = encoded[pixel_ptr];
            unsigned char temp_y2 = encoded[pixel_ptr + 1];
            unsigned char temp_y3 = encoded[pixel_ptr + 2];
            unsigned char temp_y4 = encoded[pixel_ptr + 3];
            unsigned char temp_u = encoded[pixel_ptr + 4];
            unsigned char temp_v = encoded[pixel_ptr + 5];

            yq -= temp_y1;
            encoded[pixel_ptr] = yq;
            yq -= temp_y2;
            encoded[pixel_ptr + 1] = yq;
            yq -= temp_y3;
            encoded[pixel_ptr + 2] = yq;
            yq -= temp_y4;
            encoded[pixel_ptr + 3] = yq;

            uq -= temp_u;
            encoded[pixel_ptr + 4] = uq;
            vq -= temp_v;
            encoded[pixel_ptr + 5] = vq;

            pixel_ptr += 6;
        }
    }
}
