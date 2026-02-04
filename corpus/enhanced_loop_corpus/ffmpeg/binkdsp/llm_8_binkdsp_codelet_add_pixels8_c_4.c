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
    for (i = 0; i < 16; i++) {
        pixels[0] += block[0];
        pixels[1] += block[1];
        pixels[2] += block[2];
        pixels[3] += block[3];
        pixels += line_size;
        block += 4;
    }
}
