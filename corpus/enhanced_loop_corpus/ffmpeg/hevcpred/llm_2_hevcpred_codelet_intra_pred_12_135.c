#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern ptrdiff_t stride;
extern uint16_t *src;
extern uint16_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint16_t *left_ptr = left;
    uint16_t *src_base = src - 1;
    for (i = 0; i < size; i++) {
        *left_ptr++ = *src_base;
        src_base += stride;
    }
}
