#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *block;
extern uint8_t *restrict pixels;
extern ptrdiff_t line_size;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        if (*block < -128)
            *pixels = 0;
        else if (*block > 127)
            *pixels = 255;
        else
            *pixels = (uint8_t)(*block + 128);
        block++;
        pixels++;
        if ((i + 1) % 8 == 0)
            pixels += (line_size - 8);
    }
}
