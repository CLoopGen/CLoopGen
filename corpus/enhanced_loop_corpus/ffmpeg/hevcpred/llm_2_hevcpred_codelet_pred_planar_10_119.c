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
    // Variant 1: Consecutive Memory Access via Linear Indexing with Prefetching Pattern
    // We flatten the 2D access into a linear traversal, accessing `src` consecutively.
    // The computations for `left` and `top` remain strided but are precomputed where possible.
    ptrdiff_t offset = 0;
    for (y = 0; y < size; y++) {
        int base_left_y = left[y];
        int base_left_size = left[size];
        int base_top_size = top[size];
        for (x = 0; x < size; x++) {
            int val = (size - 1 - x) * base_left_y +
                      (x + 1) * base_top_size +
                      (size - 1 - y) * top[x] +
                      (y + 1) * base_left_size +
                      size;
            src[offset++] = val >> (trafo_size + 1);
        }
    }
}
