#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *filter;
extern int filt_w;
extern uint16_t *dst;
extern int w;
extern int h;
extern  uint16_t *src;
extern ptrdiff_t src_stride;
extern ptrdiff_t dst_stride;
extern int radius;
extern int borders_top;
extern int i;
extern int j;
extern int k;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern with reversed traversal and precomputed indices
    // Change access pattern to strided across columns first, improving potential for vectorization
    // and altering cache behavior by accessing memory with larger strides initially.
    for (j = 0; j < w; j++) {
        for (i = 0; i < borders_top; i++) {
            sum = 0;
            for (k = 0; k < filt_w; k++) {
                int i_tap = i - radius + k;
                // Boundary reflection using arithmetic instead of conditional checks where possible
                i_tap = (i_tap < 0) ? -i_tap : i_tap;
                i_tap = (i_tap >= h) ? (h - 1 - (i_tap - h)) : i_tap;
                // Strided access: maintain column-major tendency in computation
                sum += filter[k] * src[i_tap * src_stride + j];
            }
            // Output written in strided manner as well
            dst[i * dst_stride + j] = sum >> 10;
        }
    }
}
