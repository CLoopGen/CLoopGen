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
for (i = borders_bottom; i < h; i += 2) {
    for (j = 0; j < w; j++) {
        for (int offset = 0; offset < 2 && (i + offset) < h; offset++) {
            sum = 0;
            for (k = 0; k < filt_w; k++) {
                int cur_i = i + offset;
                int i_tap = ((cur_i - radius + k) >= 0 ? (cur_i - radius + k) : (-(cur_i - radius + k)));
                if (i_tap >= h) {
                    i_tap = h - (i_tap - h + 1);
                }
                sum += filter[k] * src[i_tap * src_stride + j];
            }
            dst[(i + offset) * dst_stride + j] = sum >> 8;
        }
    }
}
}
