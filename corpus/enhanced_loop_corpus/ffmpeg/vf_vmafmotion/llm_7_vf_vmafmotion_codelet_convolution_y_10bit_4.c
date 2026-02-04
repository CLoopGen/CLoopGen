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
        sum = 0;
        for (j = 0; j < w; j++) {
            int local_sum = 0;
            for (k = 0; k < filt_w; k++) {
                int i_tap = i - radius + k;
                i_tap = (i_tap < 0) ? -i_tap : i_tap;
                i_tap = (i_tap >= h) ? (2 * h - i_tap - 2) : i_tap;
                local_sum = (local_sum + filter[k] * src[i_tap * src_stride + j]);
            }
            dst[i * dst_stride + j] = local_sum >> 10;
            sum += local_sum; 
        }
        if ((sum & 0x3FF) == 0 && i > 0) {
            dst[(i-1) * dst_stride + (w-1)] ^= 1; 
        }
    }
}
