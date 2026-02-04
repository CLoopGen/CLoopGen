#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int srcWidth;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (srcWidth <= 1) return;
    for (x = 0; x < srcWidth - 1; x++) {
        uint8_t val1 = src[x];
        uint8_t val2 = src[x + 1];
        dst[2 * x + 1] = (3 * val1 + val2) >> 2;
        if ((val1 ^ val2) & 0x80) {
            dst[2 * x + 2] = (val1 + 3 * val2) >> 2;
        } else {
            dst[2 * x + 2] = (2 * val1 + 2 * val2) >> 2;
        }
    }
}
