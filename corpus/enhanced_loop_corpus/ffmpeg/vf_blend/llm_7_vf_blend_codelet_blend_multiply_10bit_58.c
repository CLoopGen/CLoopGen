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
    for (i = 0; i < height; i++) {
        for (j = width - 1; j >= 0; j--) {
            int prev_j = (j > 0) ? j - 1 : 0;
            uint16_t fused_input = (j == 0) ? top[j] : (top[prev_j] + bottom[prev_j]) >> 1;
            dst[j] = fused_input + ((((1) * (((fused_input) * (bottom[j])) / 1023))) - fused_input) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
