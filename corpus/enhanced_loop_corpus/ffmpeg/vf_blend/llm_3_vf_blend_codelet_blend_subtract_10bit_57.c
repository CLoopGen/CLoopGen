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
    // Variant 2: Strided memory access – process every 2nd element in reverse order to increase stride and change access pattern
    for (i = 0; i < height; i++) {
        for (j = width - 1; j >= 0; j -= 2) {  // Reverse, strided by 2
            ptrdiff_t idx = j;
            dst[idx] = top[idx] + ((((0) > (top[idx] - bottom[idx]) ? (0) : (top[idx] - bottom[idx]))) - top[idx]) * opacity;
            // Handle adjacent element if exists (to preserve full coverage with stride 2)
            if (j > 0) {
                dst[idx - 1] = top[idx - 1] + ((((0) > (top[idx - 1] - bottom[idx - 1]) ? (0) : (top[idx - 1] - bottom[idx - 1]))) - top[idx - 1]) * opacity;
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
