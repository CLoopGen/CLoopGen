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
    int temp[8];
    for (i = 0; i < 8; i++) {
        temp[0] = block[0];
        temp[1] = block[1];
        temp[2] = block[2];
        temp[3] = block[3];
        temp[4] = block[4];
        temp[5] = block[5];
        temp[6] = block[6];
        temp[7] = block[7];
        pixels[0] += temp[0];
        pixels[1] += temp[1];
        pixels[2] += temp[2];
        pixels[3] += temp[3];
        pixels[4] += temp[4];
        pixels[5] += temp[5];
        pixels[6] += temp[6];
        pixels[7] += temp[7];
        pixels += line_size;
        block += 8;
    }
}
