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
for (i = 0; i < 16; i += 2) {
    block[0] = pixels[0] - 128;
    block[1] = pixels[1] - 128;
    block[8] = pixels[stride] - 128;
    block[9] = pixels[stride + 1] - 128;
    block[2] = pixels[2] - 128;
    block[3] = pixels[3] - 128;
    block[10] = pixels[stride + 2] - 128;
    block[11] = pixels[stride + 3] - 128;
    pixels += 2 * stride;
    block += 16;
}
}
