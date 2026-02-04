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
            int index = pixel_ptr;
            if (row > 0) {
                encoded[index] = yq -= encoded[index];
                encoded[index + 1] = yq -= encoded[index + 1];
                encoded[index + 2] = yq -= encoded[index + 2];
                encoded[index + 3] = yq -= encoded[index + 3];
            } else {
                encoded[index] = yq += encoded[index];
                encoded[index + 1] = yq += encoded[index + 1];
            }
            encoded[index + 4] = uq -= encoded[index + 4];
            encoded[index + 5] = vq -= encoded[index + 5];
            pixel_ptr += 6;
        }
    }
}
