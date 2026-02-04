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
for (i = 0; i < 4; i++) {
    for (j = 0; j < 8; j += 2) {
        int16_t val1 = *block;
        int16_t val2 = *(block + 1);
        *pixels = (uint8_t)((val1 < -128) ? 0 : (val1 > 127) ? 255 : val1 + 128);
        pixels++;
        *pixels = (uint8_t)((val2 < -128) ? 0 : (val2 > 127) ? 255 : val2 + 128);
        pixels++;
        block += 2;
    }
    pixels += (line_size - 16);
}
}
