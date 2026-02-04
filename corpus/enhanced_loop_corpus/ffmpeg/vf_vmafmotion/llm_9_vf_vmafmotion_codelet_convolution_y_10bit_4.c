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
for (i = 0; i < borders_top && filt_w > 0; i++) { // Add early exit condition and increase arithmetic intensity
    for (j = 0; j < w; j++) {
        sum = filter[0] * src[((i - radius) >= 0 ? (i - radius) : -(i - radius)) * src_stride + j]; // Precompute first term
        for (k = 1; k < filt_w; k++) {
            int i_tap = i - radius + k;
            if (i_tap < 0) i_tap = -i_tap;
            if (i_tap >= h) i_tap = h - (i_tap - h + 1);
            sum += filter[k] * src[i_tap * src_stride + j];
        }
        dst[i * dst_stride + j] = (sum + (1 << 9)) >> 10; // Add rounding before shift
    }
}
}
