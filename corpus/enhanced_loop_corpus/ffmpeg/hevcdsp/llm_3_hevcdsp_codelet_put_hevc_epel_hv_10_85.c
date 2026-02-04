#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Use strided memory access by processing transposed data layout: iterate over columns first, then rows
// Simulate column-wise traversal by adjusting pointer arithmetic accordingly
for (x = 0; x < width; x++) {
    for (y = 0; y < height + 3; y++) {
        uint16_t *src_elem = src + y * srcstride + x;
        int16_t *tmp_elem = tmp + y * 64 + x;
        *tmp_elem = (filter[0] * (*(src_elem - 1)) + filter[1] * (*src_elem) +
                     filter[2] * (*(src_elem + 1)) + filter[3] * (*(src_elem + 2))) >> 2;
    }
}
// Reset src and tmp to original calling convention expectations if needed externally
// Note: This variant changes access pattern from row-major to column-major (strided)
}
