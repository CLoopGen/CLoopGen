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
    sum = 0;
    for (j = 0; j < w; j++) {
        sum = 0;
        int base_k = 0;
        for (; base_k < filt_w; base_k++) {
            int i_tap = ((i - radius + base_k) >= 0 ? (i - radius + base_k) : (-(i - radius + base_k)));
            if (i_tap >= h) {
                i_tap = h - (i_tap - h + 1);
            }
            sum += filter[base_k] * src[i_tap * src_stride + j];
        }
        dst[i * dst_stride + j] = sum >> 10;
    }
}
}
