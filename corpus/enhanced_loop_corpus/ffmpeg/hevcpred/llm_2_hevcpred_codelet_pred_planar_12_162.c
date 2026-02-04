#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int trafo_size;
extern int x;
extern int y;
extern uint16_t *src;
extern  uint16_t *top;
extern  uint16_t *left;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access via Pointer Arithmetic
    // Instead of indexing with stride, we traverse src in a row-major consecutive manner
    // by incrementing a pointer. The nested loops are kept but access pattern is linearized.
    uint16_t *src_ptr = src;
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            *src_ptr = ((size - 1 - x) * left[y] + (x + 1) * top[size] +
                        (size - 1 - y) * top[x] + (y + 1) * left[size] + size) >> (trafo_size + 1);
            src_ptr++;
        }
    }
}
