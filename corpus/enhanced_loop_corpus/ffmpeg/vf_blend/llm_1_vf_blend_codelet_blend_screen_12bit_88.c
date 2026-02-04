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
    int idx = i;
    int row = idx / width;
    int col = idx % width;
    uint16_t *dst_ptr = (uint16_t*)((char*)dst + row * dst_linesize) + col;
    uint16_t *top_ptr = (uint16_t*)((char*)top + row * top_linesize) + col;
    uint16_t *bot_ptr = (uint16_t*)((char*)bottom + row * bottom_linesize) + col;
    dst_ptr[0] = top_ptr[0] + (((4095 - (1) * ((4095 - (top_ptr[0])) * (4095 - (bot_ptr[0])) / 4095))) - top_ptr[0]) * opacity;
}
}
