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
// Reduced loop nesting: flatten the nested structure using a single loop
// by combining row and column indices into a linear iteration.

ptrdiff_t total_elements = height * width;
for (i = 0; i < total_elements; i++) {
    ptrdiff_t row = i / width;
    ptrdiff_t col = i % width;
    uint16_t* dst_ptr = (uint16_t*)((char*)dst + row * dst_linesize) + col;
    uint16_t* top_ptr = (uint16_t*)((char*)top + row * top_linesize) + col;
    uint16_t* bottom_ptr = (uint16_t*)((char*)bottom + row * bottom_linesize) + col;
    
    *dst_ptr = *top_ptr + ((*top_ptr + *bottom_ptr - 2 * (*top_ptr) * (*bottom_ptr) / 1023) - *top_ptr) * opacity;
}
}
