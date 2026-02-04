#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *restrict pixels;
extern int16_t *block;
extern int line_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        pixels[0] += block[0]; pixels[8] += block[8];
        pixels[1] += block[1]; pixels[9] += block[9];
        pixels[2] += block[2]; pixels[10] += block[10];
        pixels[3] += block[3]; pixels[11] += block[11];
        pixels[4] += block[4]; pixels[12] += block[12];
        pixels[5] += block[5]; pixels[13] += block[13];
        pixels[6] += block[6]; pixels[14] += block[14];
        pixels[7] += block[7]; pixels[15] += block[15];
        pixels += line_size;
        block += 16;
    }
}
