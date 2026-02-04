#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *restrict block;
extern  uint8_t *pixels;
extern ptrdiff_t stride;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 4; outer++) {
    for (int mid = 0; mid < 2; mid++) {
        for (int inner = 0; inner < 1; inner++) {
            int offset = (outer * 2 + mid) * 8;
            block[0] = pixels[0];
            block[1] = pixels[1];
            block[2] = pixels[2];
            block[3] = pixels[3];
            block[4] = pixels[4];
            block[5] = pixels[5];
            block[6] = pixels[6];
            block[7] = pixels[7];
            pixels += stride;
            block += 8;
        }
    }
}
}
