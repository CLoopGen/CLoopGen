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
        block[0] = (int16_t)(pixels[0] + pixels[1] - 128);
        block[1] = (int16_t)(pixels[2] + pixels[3] - 128);
        block[2] = (int16_t)(pixels[4] + pixels[5] - 128);
        block[3] = (int16_t)(pixels[6] + pixels[7] - 128);
        block[4] = (int16_t)(pixels[0] - pixels[1] + 128);
        block[5] = (int16_t)(pixels[2] - pixels[3] + 128);
        block[6] = (int16_t)(pixels[4] - pixels[5] + 128);
        block[7] = (int16_t)(pixels[6] - pixels[7] + 128);
        pixels += line_size;
        block += 8;
    }
}
