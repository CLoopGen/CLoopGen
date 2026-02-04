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
    for (i = 0; i < 8; i++) {
        uint8_t sum = 0;
        for (int j = 0; j < 8; j++) {
            sum += block[j];
        }
        pixels[0] += sum;
        pixels[1] += sum;
        pixels[2] += sum;
        pixels[3] += sum;
        pixels[4] += sum;
        pixels[5] += sum;
        pixels[6] += sum;
        pixels[7] += sum;
        pixels += line_size;
        block += 8;
    }
}
