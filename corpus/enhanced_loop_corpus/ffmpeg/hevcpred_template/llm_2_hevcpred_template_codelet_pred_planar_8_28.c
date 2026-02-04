#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int trafo_size;
extern int x;
extern int y;
extern uint8_t *src;
extern  uint8_t *top;
extern  uint8_t *left;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Reversed Traversal Order
    // Instead of row-major, traverse in reverse column-major to improve spatial locality
    // and access src consecutively in memory by flipping loop order and indexing.
    ptrdiff_t s = stride;
    for (x = size - 1; x >= 0; x--)
        for (y = size - 1; y >= 0; y--)
            src[(y) + s * (x)] = ((size - 1 - y) * left[x] + (y + 1) * top[size] + (size - 1 - x) * top[y] + (x + 1) * left[size] + size) >> (trafo_size + 1);
}
