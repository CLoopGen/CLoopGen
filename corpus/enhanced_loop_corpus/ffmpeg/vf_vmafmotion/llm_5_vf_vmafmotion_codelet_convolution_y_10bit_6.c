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
extern int borders_bottom;
extern int i;
extern int j;
extern int k;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = borders_bottom; i < h; i++) {
    for (j = 0; j < w; j++) {
        sum = 0;
        for (k = 0; k < filt_w; k++) {
            int idx = i - radius + k;
            // Eliminate branching by using absolute value and clamping logic through arithmetic
            int neg_mask = (idx < 0) - (idx >= h); // -1 if idx<0, 0 if in range, 1 if idx>=h
            int i_tap = (neg_mask & (-idx)) | 
                        ((~neg_mask & (neg_mask+1)) & (h - (idx - h + 1))) | 
                        (((idx >= 0) & (idx < h)) & idx);
            sum += filter[k] * src[i_tap * src_stride + j];
        }
        dst[i * dst_stride + j] = sum >> 10;
    }
}
}
