#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int x;
extern int size;
extern uint16_t *src;
extern  uint16_t *top;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint16_t *dst = src + stride * 0;
    for (x = 1; x < size; x++) {
        dst[x] = (top[x] + 3 * dc + 2) >> 2;
    }
}
