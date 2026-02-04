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
for (i = borders_top; i < borders_bottom; i++) {
    for (j = 0; j < w; j++) {
        sum = 0;
        k = 0;
        #pragma unroll
        while (k < filt_w) {
            sum += filter[k] * src[(i - radius + k) * src_stride + j];
            k++;
        }
        dst[i * dst_stride + j] = sum >> 10;
    }
}
}
