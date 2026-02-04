#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            int offset = (8) + 7 - y;
            int coeff1 = 8 - x;
            int coeff2 = x;
            int val1 = src[offset];
            int val2 = src[(8 + 8 + 1) + x];
            dst[x] = (val1 * coeff1 + val2 * coeff2 + 4) >> 3;
        }
        dst += stride;
    }
}
