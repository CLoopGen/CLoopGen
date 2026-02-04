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
            dst[j] = top[j] + (((4095 - ((4095 - top[j]) * (4095 - bottom[j]) / 4095)) - top[j])) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;

    if (i + 1 < height) {
        uint16_t *dst_row = (uint16_t*)((char*)dst + dst_linesize);
        uint16_t *top_row = (uint16_t*)((char*)top + top_linesize);
        uint16_t *bottom_row = (uint16_t*)((char*)bottom + bottom_linesize);
        for (j = 0; j < width; j++) {
            dst_row[j] = top_row[j] + (((4095 - ((4095 - top_row[j]) * (4095 - bottom_row[j]) / 4095)) - top_row[j])) * opacity;
        }
    }

    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
