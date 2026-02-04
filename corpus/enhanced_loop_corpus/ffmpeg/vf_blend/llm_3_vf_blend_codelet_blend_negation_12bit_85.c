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
    uint16_t *dst_ptr = dst;
    uint16_t *top_ptr = top;
    uint16_t *bottom_ptr = bottom;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j += 2) {
            if (j + 1 < width) {
                dst_ptr[j]   = top_ptr[j] + ((4095 - ((4095 - top_ptr[j] - bottom_ptr[j]) >= 0 ? (4095 - top_ptr[j] - bottom_ptr[j]) : (-(4095 - top_ptr[j] - bottom_ptr[j])))) - top_ptr[j]) * opacity;
                dst_ptr[j+1] = top_ptr[j+1] + ((4095 - ((4095 - top_ptr[j+1] - bottom_ptr[j+1]) >= 0 ? (4095 - top_ptr[j+1] - bottom_ptr[j+1]) : (-(4095 - top_ptr[j+1] - bottom_ptr[j+1])))) - top_ptr[j+1]) * opacity;
            } else {
                dst_ptr[j] = top_ptr[j] + ((4095 - ((4095 - top_ptr[j] - bottom_ptr[j]) >= 0 ? (4095 - top_ptr[j] - bottom_ptr[j]) : (-(4095 - top_ptr[j] - bottom_ptr[j])))) - top_ptr[j]) * opacity;
            }
        }
        dst_ptr += dst_linesize;
        top_ptr += top_linesize;
        bottom_ptr += bottom_linesize;
    }
}
