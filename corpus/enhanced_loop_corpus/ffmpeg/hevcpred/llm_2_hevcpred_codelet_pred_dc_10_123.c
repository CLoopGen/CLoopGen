#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int y;
extern int size;
extern uint16_t *src;
extern  uint16_t *left;
extern int dc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Pointer Arithmetic
    uint16_t *src_ptr = src + stride;
    uint16_t *left_ptr = left + 1;
    for (y = 1; y < size; y++) {
        *src_ptr = (*left_ptr + 3 * dc + 2) >> 2;
        src_ptr += stride;
        left_ptr++;
    }
}
