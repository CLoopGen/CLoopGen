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
for (i = 0; i < borders_top; i++) {
    for (j = 0; j < w; j += 2) { // Double the step in j to reduce trip count and increase per-iteration work
        sum = 0;
        int sum2 = 0;
        for (k = 0; k < filt_w; k++) {
            int i_tap = ((i - radius + k) >= 0 ? (i - radius + k) : (-(i - radius + k)));
            if (i_tap >= h) {
                i_tap = h - (i_tap - h + 1);
            }
            int src_idx = i_tap * src_stride + j;
            sum += filter[k] * src[src_idx];
            if (j + 1 < w) {
                sum2 += filter[k] * src[src_idx + 1];
            }
        }
        dst[i * dst_stride + j] = sum >> 10;
        if (j + 1 < w) {
            dst[i * dst_stride + j + 1] = sum2 >> 10;
        }
    }
}
}
