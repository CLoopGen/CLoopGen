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
    for (int outer = 0; outer < 2; outer++) {
        for (int inner = 0; inner < 4; inner++) {
            int idx = inner * 2;
            pixels[0] += block[idx + 0];
            pixels[1] += block[idx + 1];
            pixels[2] += block[idx + 2];
            pixels[3] += block[idx + 3];
            pixels += line_size / 2;
            block += 4;
        }
    }
}
