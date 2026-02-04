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
    // Variant 1: Strided memory access with stride of 2 (process every other element in reverse order within each row)
    for (i = 0; i < height; i++) {
        for (j = width - (width % 2); j >= 0; j -= 2) {  // Reverse even-indexed traversal
            ptrdiff_t idx = j;  // Stride index
            dst[idx] = top[idx] + (((bottom[idx] < 512) ? ((top[idx] > (2 * bottom[idx])) ? (2 * bottom[idx]) : top[idx]) : ((top[idx] > (2 * (bottom[idx] - 512))) ? top[idx] : (2 * (bottom[idx] - 512)))) - top[idx]) * opacity;
            // Handle odd width by processing last element if needed
            if (j == 1) {
                dst[0] = top[0] + (((bottom[0] < 512) ? ((top[0] > (2 * bottom[0])) ? (2 * bottom[0]) : top[0]) : ((top[0] > (2 * (bottom[0] - 512))) ? top[0] : (2 * (bottom[0] - 512)))) - top[0]) * opacity;
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
