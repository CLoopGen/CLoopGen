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
    for (j = 0; j < width; j += 2) {
        // Unroll loop by processing two elements per iteration with conditional skipping
        if (j + 1 >= width) {
            // Handle last odd element without unrolling
            uint16_t t = top[j];
            dst[j] = t + (((t == 65535) ? 0 : ((bottom[j] * bottom[j] / (65535 - t)) > 65535 ? 65535 - t : (bottom[j] * bottom[j] / (65535 - t)) - t)) * opacity);
        } else {
            // Process j and j+1 separately but within same iteration, skip computation if top is saturated
            uint16_t t0 = top[j], t1 = top[j+1];
            uint16_t b0 = bottom[j], b1 = bottom[j+1];

            // First element
            if (t0 != 65535) {
                uint32_t div0 = 65535 - t0;
                uint16_t comp0 = (div0 > 0) ? (b0 * b0 / div0) : 65535;
                comp0 = (comp0 > 65535) ? 65535 : comp0;
                dst[j] = t0 + (comp0 - t0) * opacity;
            } else {
                dst[j] = t0;
            }

            // Second element
            if (t1 != 65535) {
                uint32_t div1 = 65535 - t1;
                uint16_t comp1 = (div1 > 0) ? (b1 * b1 / div1) : 65535;
                comp1 = (comp1 > 65535) ? 65535 : comp1;
                dst[j+1] = t1 + (comp1 - t1) * opacity;
            } else {
                dst[j+1] = t1;
            }
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
