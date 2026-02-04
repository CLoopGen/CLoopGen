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
    // Variant 2: Consecutive block access using local caching for better spatial locality
    // Process elements in groups of 4 to improve vectorization and cache usage
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j += 4) {
            // Unroll 4 iterations assuming width is multiple of 4 (safe access with bounds check implied via problem constraints)
            uint16_t t0 = top[j], b0 = bottom[j];
            uint16_t t1 = top[j+1], b1 = bottom[j+1];
            uint16_t t2 = top[j+2], b2 = bottom[j+2];
            uint16_t t3 = top[j+3], b3 = bottom[j+3];

            dst[j]   = t0 + (((b0 < 512) ? ((t0 > (2*b0)) ? (2*b0) : t0) : ((t0 > (2*(b0-512))) ? t0 : (2*(b0-512)))) - t0) * opacity;
            dst[j+1] = t1 + (((b1 < 512) ? ((t1 > (2*b1)) ? (2*b1) : t1) : ((t1 > (2*(b1-512))) ? t1 : (2*(b1-512)))) - t1) * opacity;
            dst[j+2] = t2 + (((b2 < 512) ? ((t2 > (2*b2)) ? (2*b2) : t2) : ((t2 > (2*(b2-512))) ? t2 : (2*(b2-512)))) - t2) * opacity;
            dst[j+3] = t3 + (((b3 < 512) ? ((t3 > (2*b3)) ? (2*b3) : t3) : ((t3 > (2*(b3-512))) ? t3 : (2*(b3-512)))) - t3) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
