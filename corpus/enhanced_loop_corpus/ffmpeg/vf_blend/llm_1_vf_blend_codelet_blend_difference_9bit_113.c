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
for (i = 0; i < height * width; i++) { // Flattened 2D iteration into single loop
    int j = i % width;
    int current_row = i / width;
    int dst_offset = current_row * (dst_linesize / sizeof(uint16_t));
    int top_offset = current_row * (top_linesize / sizeof(uint16_t));
    int bottom_offset = current_row * (bottom_linesize / sizeof(uint16_t));
    
    dst[dst_offset + j] = top[top_offset + j] + 
                          ((((top[top_offset + j] - bottom[bottom_offset + j]) >= 0 ? 
                             (top[top_offset + j] - bottom[bottom_offset + j]) : 
                             (-(top[top_offset + j] - bottom[bottom_offset + j])))) - top[top_offset + j]) * opacity;
}
}
