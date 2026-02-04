#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Access with Transposed Indexing via Pointer Arithmetic
    // Use a fixed stride and step through arrays using pointer arithmetic with constant increments
    // Simulates a more regular memory pattern useful in SIMD or vectorized contexts
    int16_t *dst_row = dst;
    int16_t *tmp_row = tmp;
    for (y = 0; y < height; y++) {
        int16_t *tmp_x = tmp_row;
        for (x = 0; x < width; x++, tmp_x++) {
            dst_row[x] = (filter[0] * *(tmp_x - 64) +
                          filter[1] * *(tmp_x) +
                          filter[2] * *(tmp_x + 64) +
                          filter[3] * *(tmp_x + 128)) >> 6;
        }
        tmp_row += 64;
        dst_row += 64;
    }
}
