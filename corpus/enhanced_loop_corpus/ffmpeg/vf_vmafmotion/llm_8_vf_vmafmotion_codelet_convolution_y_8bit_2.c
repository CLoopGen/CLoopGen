#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *filter;
extern int filt_w;
extern uint16_t *dst;
extern int w;
extern  uint8_t *src;
extern ptrdiff_t src_stride;
extern ptrdiff_t dst_stride;
extern int radius;
extern int borders_top;
extern int borders_bottom;
extern int i;
extern int j;
extern int k;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = borders_top; i < borders_bottom; i++) {
        for (j = 0; j < w; j += 2) {
            sum = 0;
            int sum2 = 0;
            for (k = 0; k < filt_w; k++) {
                sum += filter[k] * src[(i - radius + k) * src_stride + j];
                if (j + 1 < w) {
                    sum2 += filter[k] * src[(i - radius + k) * src_stride + j + 1];
                }
            }
            dst[i * dst_stride + j] = sum >> 8;
            if (j + 1 < w) {
                dst[i * dst_stride + j + 1] = sum2 >> 8;
            }
        }
    }
}
