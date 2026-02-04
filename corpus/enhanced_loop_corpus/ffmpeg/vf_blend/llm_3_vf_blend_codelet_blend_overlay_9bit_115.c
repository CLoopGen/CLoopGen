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
    // Variant 2: Strided memory access – process every 2nd element forward, then backward to cover all
    for (i = 0; i < height; i++) {
        // Forward pass: even indices
        for (j = 0; j < width; j += 2) {
            dst[j] = top[j] + (((top[j] < 256) ? ((2) * (((top[j]) * (bottom[j])) / 511)) : (511 - (2) * ((511 - (top[j])) * (511 - (bottom[j])) / 511))) - top[j]) * opacity;
        }
        // Backward pass: odd indices
        for (j = (width % 2 == 0) ? width - 1 : width - 2; j > 0; j -= 2) {
            dst[j] = top[j] + (((top[j] < 256) ? ((2) * (((top[j]) * (bottom[j])) / 511)) : (511 - (2) * ((511 - (top[j])) * (511 - (bottom[j])) / 511))) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
