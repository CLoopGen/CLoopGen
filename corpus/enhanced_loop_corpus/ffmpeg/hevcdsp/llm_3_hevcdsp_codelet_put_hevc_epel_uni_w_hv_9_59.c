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
// Change to strided memory access by transposing the effective indexing
// Simulate accessing data in a column-major-like fashion with stride over rows
ptrdiff_t effective_stride = srcstride / sizeof(uint16_t); // convert byte stride to element count
for (x = 0; x < width; x++) {
    for (y = 0; y < height + 3; y++) {
        uint16_t *current_src = src + y * effective_stride;
        int16_t *current_tmp = tmp + y * 64;
        current_tmp[x] = (filter[0] * current_src[x - 1] + 
                          filter[1] * current_src[x] + 
                          filter[2] * current_src[x + 1] + 
                          filter[3] * current_src[x + 2]) >> 1;
    }
}
}
