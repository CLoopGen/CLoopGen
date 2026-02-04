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
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            int16_t val = *block;
            *pixels = (val < -128) ? 0 : 
                     (val > 127) ? 255 : 
                     (uint8_t)(val + 128);
            block++;
            pixels++;
        }
        pixels += (line_size - 8);
    }
}
