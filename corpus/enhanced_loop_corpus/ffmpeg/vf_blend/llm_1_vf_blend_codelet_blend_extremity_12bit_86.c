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
    ptrdiff_t dst_offset = current_row * dst_linesize;
    ptrdiff_t top_offset = current_row * top_linesize;
    ptrdiff_t bottom_offset = current_row * bottom_linesize;

    ((uint16_t*)((char*)dst + dst_offset))[j] = 
        ((uint16_t*)((char*)top + top_offset))[j] + 
        ((((4095 - ((uint16_t*)((char*)top + top_offset))[j] - ((uint16_t*)((char*)bottom + bottom_offset))[j]) >= 0 ? 
           (4095 - ((uint16_t*)((char*)top + top_offset))[j] - ((uint16_t*)((char*)bottom + bottom_offset))[j]) : 
           (-(4095 - ((uint16_t*)((char*)top + top_offset))[j] - ((uint16_t*)((char*)bottom + bottom_offset))[j])))) - 
         ((uint16_t*)((char*)top + top_offset))[j]) * opacity;
}
}
