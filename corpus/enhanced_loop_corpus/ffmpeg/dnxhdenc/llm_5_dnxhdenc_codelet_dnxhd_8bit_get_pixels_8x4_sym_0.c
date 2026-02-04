#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *restrict block;
extern  uint8_t *pixels;
extern ptrdiff_t line_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    int skip_write = (i & 1); // Skip every other iteration (i = 1, 3)
    if (!skip_write) {
        block[0] = pixels[0];
        block[1] = pixels[1];
        block[2] = pixels[2];
        block[3] = pixels[3];
        block[4] = pixels[4];
        block[5] = pixels[5];
        block[6] = pixels[6];
        block[7] = pixels[7];
    }
    pixels += line_size;
    block += 8;
}
}
