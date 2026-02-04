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
    // Variant 2: Strided memory access with transposed indexing
    // Instead of row-major traversal, simulate a strided vertical access pattern by precomputing base pointers
    uint16_t *src_base = src;
    int16_t *tmp_base = tmp;
    for (x = 0; x < width; x++) {
        int16_t *tmp_col = tmp_base + x;
        uint16_t *src_col = src_base + x - 1;
        for (y = 0; y < height + 3; y++) {
            tmp_col[0] = (filter[0] * src_col[0] + filter[1] * src_col[1] + 
                          filter[2] * src_col[2] + filter[3] * src_col[3]) >> 1;
            src_col = (uint16_t*)((char*)src_col + srcstride); // Advance src_col vertically
            tmp_col += 64; // Move to next row in tmp (fixed stride)
        }
    }
    // Update global src and tmp to reflect final state as in original
    src = src_base + (height + 3) * srcstride;
    tmp = tmp_base + (height + 3) * 64;
}
