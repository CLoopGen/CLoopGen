#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *filter;
extern int filt_w;
extern uint16_t *dst;
extern int w;
extern  uint16_t *src;
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
for (i = borders_top; i < borders_bottom; i += 2) { // Process two rows per outer loop iteration
    if (i + 1 < borders_bottom) {
        for (j = 0; j < w; j++) {
            sum = 0;
            int sum_next = 0;
            for (k = 0; k < filt_w; k++) {
                sum += filter[k] * src[(i - radius + k) * src_stride + j];
                sum_next += filter[k] * src[(i - radius + k + 1) * src_stride + j];
            }
            dst[i * dst_stride + j] = sum >> 10;
            dst[(i + 1) * dst_stride + j] = sum_next >> 10;
        }
    } else {
        // Handle last row if borders_bottom is odd
        for (j = 0; j < w; j++) {
            sum = 0;
            for (k = 0; k < filt_w; k++) {
                sum += filter[k] * src[(i - radius + k) * src_stride + j];
            }
            dst[i * dst_stride + j] = sum >> 10;
        }
    }
}
}
