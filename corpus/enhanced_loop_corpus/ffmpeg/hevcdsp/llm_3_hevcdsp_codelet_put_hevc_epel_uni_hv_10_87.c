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
uint16_t *src_base = src;
int16_t *tmp_base = tmp;
for (y = 0; y < height + 3; y++) {
    ptrdiff_t row_offset = y * srcstride;
    for (x = 0; x < width; x++) {
        // Consecutive, precomputed base pointer access
        uint16_t *row_src = (uint16_t*)((char*)src_base + row_offset);
        tmp_base[x] = (filter[0] * row_src[x - 1] + filter[1] * row_src[x] + 
                       filter[2] * row_src[x + 1] + filter[3] * row_src[x + 2]) >> 2;
    }
    tmp_base += 64;
}
}
