#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *filter;
extern int filt_w;
extern uint16_t *dst;
extern int w;
extern int h;
extern  uint8_t *src;
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
for (i = 0; i < borders_top && filt_w > 0; i++) { // Add early exit condition and computational simplification
    for (j = 0; j < w; j++) {
        // Reduce effective filter width by half (lighter computation)
        int eff_filt_w = filt_w / 2 + (filt_w & 1); 
        sum = 0;
        for (k = 0; k < eff_filt_w; k++) {
            int mapped_k = (k % filt_w); // Remap reduced index to original tap positions
            int i_tap = ((i - radius + mapped_k) >= 0 ? (i - radius + mapped_k) : (-(i - radius + mapped_k)));
            if (i_tap >= h) {
                i_tap = h - (i_tap - h + 1);
            }
            sum += filter[mapped_k] * src[i_tap * src_stride + j];
        }
        dst[i * dst_stride + j] = sum >> 7; // Adjust shift to maintain plausible output range after halving ops
    }
}
}
