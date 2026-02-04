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
    int16_t *b = block;
    uint8_t *p = pixels;
    ptrdiff_t ls = line_size;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            int16_t val = *b;
            uint8_t result;
            if (val < -128)
                result = 0;
            else if (val > 127)
                result = 255;
            else
                result = (uint8_t)(val + 128);
            *p = result;
            b++;
            p++;
        }
        p += (ls - 8);
    }
    block = b;
    pixels = p - (ls * 8) + 8; // Restore original base, adjust for total advance
}
