#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int src_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint8_t *d = dst;
    const uint8_t *s = src;
    int limit = (src_size / 3) * 3; // Ensure we don't exceed bounds
    for (i = 0; 3 * i < src_size; i++) {
        d[0] = s[2];
        d[1] = s[1];
        d[2] = s[0];
        d[3] = 255;
        d += 4;
        s += 3;
    }
}
