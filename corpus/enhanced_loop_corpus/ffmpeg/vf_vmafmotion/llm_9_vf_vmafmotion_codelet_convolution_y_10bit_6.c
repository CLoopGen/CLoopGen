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
for (i = borders_bottom; i < h; i += 2) {
    if (i + 1 < h) {
        for (j = 0; j < w; j++) {
            sum = 0;
            int sum_next = 0;
            for (k = 0; k < filt_w; k++) {
                int i_tap = ((i - radius + k) >= 0 ? (i - radius + k) : (-(i - radius + k)));
                int i_tap_next = ((i + 1 - radius + k) >= 0 ? (i + 1 - radius + k) : (-(i + 1 - radius + k)));
                if (i_tap >= h) {
                    i_tap = h - (i_tap - h + 1);
                }
                if (i_tap_next >= h) {
                    i_tap_next = h - (i_tap_next - h + 1);
                }
                sum += filter[k] * src[i_tap * src_stride + j];
                sum_next += filter[k] * src[i_tap_next * src_stride + j];
            }
            dst[i * dst_stride + j] = sum >> 10;
            dst[(i + 1) * dst_stride + j] = sum_next >> 10;
        }
    } else {
        for (j = 0; j < w; j++) {
            sum = 0;
            for (k = 0; k < filt_w; k++) {
                int i_tap = ((i - radius + k) >= 0 ? (i - radius + k) : (-(i - radius + k)));
                if (i_tap >= h) {
                    i_tap = h - (i_tap - h + 1);
                }
                sum += filter[k] * src[i_tap * src_stride + j];
            }
            dst[i * dst_stride + j] = sum >> 10;
        }
    }
}
}
