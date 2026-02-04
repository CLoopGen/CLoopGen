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
    // Variant 1: Consecutive memory access with pointer arithmetic for src and dst
    for (i = borders_top; i < borders_bottom; i++) {
        uint16_t *src_base = &src[(i - radius) * src_stride];
        uint16_t *dst_row = &dst[i * dst_stride];
        for (j = 0; j < w; j++) {
            sum = 0;
            const uint16_t *src_ptr = src_base + j;
            for (k = 0; k < filt_w; k++) {
                sum += filter[k] * src_ptr[k * src_stride];
            }
            dst_row[j] = sum >> 10;
        }
    }
}
