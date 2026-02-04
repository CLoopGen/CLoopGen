#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern uint8_t *last;
extern int size;
extern int i;
extern int r;
extern int g;
extern int b;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled pattern
    // Access elements in groups of 3 but reorganize to promote spatial locality
    for (; i <= size - 3; i += 3) {
        uint8_t s0 = src[i + 0], s1 = src[i + 1], s2 = src[i + 2];
        uint8_t l0 = last[i + 0], l1 = last[i + 1], l2 = last[i + 2];

        dst[i + 0] = r = ((((r + l0) >> 1) + s0) & 255);
        dst[i + 1] = g = ((((g + l1) >> 1) + s1) & 255);
        dst[i + 2] = b = ((((b + l2) >> 1) + s2) & 255);
    }
}
