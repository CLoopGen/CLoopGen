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
for (i = 0; i < 4; i++) {
    block[0] = pixels[0];
    block[1] = pixels[1];
    block[2] = pixels[2];
    block[3] = pixels[3];
    block[4] = pixels[stride];
    block[5] = pixels[stride + 1];
    block[6] = pixels[stride + 2];
    block[7] = pixels[stride + 3];
    pixels += 2 * stride;
    block += 8;
}
}
