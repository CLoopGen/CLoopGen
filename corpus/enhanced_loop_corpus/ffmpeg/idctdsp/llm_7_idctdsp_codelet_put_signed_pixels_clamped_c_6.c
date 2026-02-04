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
    int16_t *local_block = block;
    uint8_t *local_pixels = pixels;
    for (i = 0; i < 64; i++) {
        int16_t val = local_block[i];
        uint8_t clamped;
        if (val < -128)
            clamped = 0;
        else if (val > 127)
            clamped = 255;
        else
            clamped = (uint8_t)(val + 128);
        local_pixels[i + (i / 8) * (line_size - 8)] = clamped;
    }
}
