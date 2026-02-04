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
    // Strided access: process every 2nd element forward, then fill in backwards
    for (i = 0; i < height; i++) {
        // Forward pass: even indices
        for (j = 0; j < width; j += 2) {
            dst[j] = top[j] + (((top[j] == 511) ? top[j] : ((511) > ((bottom[j] * bottom[j] / (511 - top[j]))) ? ((bottom[j] * bottom[j] / (511 - top[j]))) : (511))) - top[j]) * opacity;
        }
        // Backward pass: odd indices
        for (j = width - (width % 2 == 0 ? 1 : 2); j >= 0; j -= 2) {
            if (j % 2 != 0) {
                dst[j] = top[j] + (((top[j] == 511) ? top[j] : ((511) > ((bottom[j] * bottom[j] / (511 - top[j]))) ? ((bottom[j] * bottom[j] / (511 - top[j]))) : (511))) - top[j]) * opacity;
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
