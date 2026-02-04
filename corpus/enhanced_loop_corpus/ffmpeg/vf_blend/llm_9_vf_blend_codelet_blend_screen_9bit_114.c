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
    // Reduced computational intensity: unroll inner loop by factor of 2 and simplify arithmetic
    // Also reduce effective trip count by processing wider steps
    for (i = 0; i < height; i++) {
        j = 0;
        // Inner loop unrolled with step size 2
        for (; j <= width - 2; j += 2) {
            // Simplify the blending formula: replace division by 511 with right shift (~ divide by 512)
            // Approximate: (a * b / 511) -> (a * b) >> 9
            int t1 = top[j], b1 = bottom[j];
            int t2 = top[j+1], b2 = bottom[j+1];

            int mix1 = (511 - (((511 - t1) * (511 - b1)) >> 9));
            int mix2 = (511 - (((511 - t2) * (511 - b2)) >> 9));

            dst[j]   = t1 + (int)((mix1 - t1) * opacity);
            dst[j+1] = t2 + (int)((mix2 - t2) * opacity);
        }
        // Handle leftover element
        if (j < width) {
            int t = top[j], b = bottom[j];
            int mix = (511 - (((511 - t) * (511 - b)) >> 9));
            dst[j] = t + (int)((mix - t) * opacity);
        }

        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
