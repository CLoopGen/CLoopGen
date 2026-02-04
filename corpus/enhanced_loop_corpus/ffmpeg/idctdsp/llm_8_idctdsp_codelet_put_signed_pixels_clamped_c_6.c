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
int i, j;
for (i = 0; i < 16; i++) {
    for (j = 0; j < 4; j++) {
        int16_t val = *block;
        uint8_t pixel_val;
        if (val < -128)
            pixel_val = 0;
        else if (val > 127)
            pixel_val = 255;
        else
            pixel_val = (uint8_t)(val + 128);
        *pixels = pixel_val;
        block++;
        pixels++;
    }
    pixels += (line_size - 4);
}
}
