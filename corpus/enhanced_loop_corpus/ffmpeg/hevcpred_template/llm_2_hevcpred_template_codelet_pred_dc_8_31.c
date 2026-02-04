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
    // Variant 1: Consecutive Memory Access with Pointer Arithmetic
    uint8_t *src_base = src + stride * 0;
    uint8_t *top_ptr = top + 1;
    uint8_t *src_ptr = src_base + 1;
    int x_local;
    for (x_local = 1; x_local < size; x_local++) {
        *(src_ptr++) = ((*top_ptr++) + 3 * dc + 2) >> 2;
    }
}
