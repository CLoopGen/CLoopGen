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
    // Variant 1: Consecutive Memory Access with Pointer Arithmetic
    uint16_t *top_ptr = top;
    uint16_t *bottom_ptr = bottom;
    uint16_t *dst_ptr = dst;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            uint16_t top_val = *(top_ptr + j);
            uint16_t bottom_val = *(bottom_ptr + j);
            uint16_t result = (bottom_val == 4095) ? bottom_val : 
                              ((top_val * top_val / (4095 - bottom_val)) > 4095 ? 4095 : (top_val * top_val / (4095 - bottom_val)));
            *(dst_ptr + j) = top_val + (result - top_val) * opacity;
        }
        dst_ptr += dst_linesize;
        top_ptr += top_linesize;
        bottom_ptr += bottom_linesize;
    }
}
