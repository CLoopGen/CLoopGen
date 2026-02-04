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
    for (j = 0; j < w; j++) {
        sum = 0;
        for (k = 0; k < filt_w; k++) {
            int index = (i - radius + k) * src_stride + j;
            if (index >= 0) {
                sum += filter[k] * src[index];
            }
        }
        dst[i * dst_stride + j] = sum >> 8;
    }
}
}
