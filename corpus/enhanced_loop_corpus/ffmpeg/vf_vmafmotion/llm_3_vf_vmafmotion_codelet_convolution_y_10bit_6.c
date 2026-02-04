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
        const uint16_t *src_j_base = &src[j]; 
        for (k = 0; k < filt_w; k++) {
            int i_tap = i - radius + k;
            if (i_tap < 0) i_tap = -i_tap;
            if (i_tap >= h) i_tap = h - 1 - (i_tap - h);
            sum += filter[k] * src_j_base[i_tap * src_stride];
        }
        dst[i * dst_stride + j] = sum >> 10;
    }
}
}
