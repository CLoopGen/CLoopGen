#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t top_linesize;
extern ptrdiff_t bottom_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern  uint16_t *top;
extern  uint16_t *bottom;
extern uint16_t *dst;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i += 2) {
    for (j = 0; j < width; j++) {
        if (i < height) {
            dst[j] = top[j] + ((((top[j]) > (bottom[j]) ? (bottom[j]) : (top[j]))) - top[j]) * opacity;
        }
        if (i + 1 < height) {
            uint16_t *dst_next = (uint16_t*)((char*)dst + dst_linesize);
            uint16_t *top_next = (uint16_t*)((char*)top + top_linesize);
            uint16_t *bottom_next = (uint16_t*)((char*)bottom + bottom_linesize);
            dst_next[j] = top_next[j] + ((((top_next[j]) > (bottom_next[j]) ? (bottom_next[j]) : (top_next[j]))) - top_next[j]) * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
