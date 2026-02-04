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
    for (j = 0; j < w; j++) {
        sum = 0;
        for (k = 0; k < filt_w; k++) {
            int tap_offset = i - radius + k;
            // Introduce early skip condition for out-of-bounds taps instead of reflection
            if (tap_offset < 0 || tap_offset >= h) {
                continue;
            }
            sum += filter[k] * src[tap_offset * src_stride + j];
        }
        dst[i * dst_stride + j] = sum >> 8;
    }
}
}
