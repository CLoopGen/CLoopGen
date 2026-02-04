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
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint8_t *s = src;
    uint8_t *d = dst + 1;
    int limit = srcWidth - 1;
    for (x = 0; x < limit; x++) {
        uint8_t s0 = *s;
        uint8_t s1 = *(s + 1);
        *d = (s0 * 3 + s1) >> 2;
        *(d + 1) = (s0 + s1 * 3) >> 2;
        s++;
        d += 2;
    }
}
