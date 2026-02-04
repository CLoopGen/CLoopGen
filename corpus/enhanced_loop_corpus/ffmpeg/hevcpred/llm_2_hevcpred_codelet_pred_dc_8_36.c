#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int x;
extern int size;
extern uint8_t *src;
extern  uint8_t *top;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint8_t *dst = src + stride * 0;
    uint8_t *top_ptr = top + 1;
    for (x = 1; x < size; x++) {
        *dst = (*top_ptr + 3 * dc + 2) >> 2;
        dst++;
        top_ptr++;
    }
}
