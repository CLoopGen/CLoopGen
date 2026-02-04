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
for (i = 0; i < height * width; i++) {
    int j = i % width;
    int current_row = i / width;
    uint16_t *current_dst = (uint16_t*)((char*)dst + current_row * dst_linesize);
    uint16_t *current_top = (uint16_t*)((char*)top + current_row * top_linesize);
    uint16_t *current_bottom = (uint16_t*)((char*)bottom + current_row * bottom_linesize);
    current_dst[j] = current_top[j] + (((current_top[j] + current_bottom[j]) / 2) - current_top[j]) * opacity;
}
}
