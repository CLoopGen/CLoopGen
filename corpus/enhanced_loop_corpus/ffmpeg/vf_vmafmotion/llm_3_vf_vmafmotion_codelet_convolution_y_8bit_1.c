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
extern int borders_top;
extern int i;
extern int j;
extern int k;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Precomputed Tap Offsets
    int tap_offsets[32]; // Assuming maximum filt_w is 32 for stack allocation
    for (k = 0; k < filt_w; k++) {
        tap_offsets[k] = (k - radius) * src_stride; // Precompute vertical stride offsets
    }

    for (i = 0; i < borders_top; i++) {
        for (j = 0; j < w; j++) {
            sum = 0;
            for (k = 0; k < filt_w; k++) {
                int offset = i * src_stride + j + tap_offsets[k];
                int i_tap = i - radius + k;

                if (i_tap < 0) {
                    i_tap = -i_tap;
                    offset = i_tap * src_stride + j;
                }
                if (i_tap >= h) {
                    i_tap = h - (i_tap - h + 1);
                    offset = i_tap * src_stride + j;
                }
                sum += filter[k] * src[offset];
            }
            dst[i * dst_stride + j] = sum >> 8;
        }
    }
}
