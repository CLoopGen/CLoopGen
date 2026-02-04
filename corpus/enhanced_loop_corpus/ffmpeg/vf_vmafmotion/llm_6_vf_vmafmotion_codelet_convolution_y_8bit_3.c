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
extern int borders_bottom;
extern int i;
extern int j;
extern int k;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = borders_bottom; i < h; i++) {
        int temp_sum[w]; // Introduce local array to break WAW and RAW dependencies across j iterations
        for (j = 0; j < w; j++) {
            temp_sum[j] = 0;
            for (k = 0; k < filt_w; k++) {
                int i_tap = i - radius + k;
                if (i_tap < 0) i_tap = -i_tap;
                if (i_tap >= h) i_tap = h - (i_tap - h + 1);
                temp_sum[j] += filter[k] * src[i_tap * src_stride + j];
            }
        }
        // Write back to dst outside inner loop: eliminates potential RAW/WAW on dst
        for (j = 0; j < w; j++) {
            dst[i * dst_stride + j] = temp_sum[j] >> 8;
        }
    }
}
