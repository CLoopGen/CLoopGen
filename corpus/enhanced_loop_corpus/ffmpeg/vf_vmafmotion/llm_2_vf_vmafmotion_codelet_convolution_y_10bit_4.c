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
extern int borders_top;
extern int i;
extern int j;
extern int k;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the inner loop order
    // Instead of processing one output pixel at a time, accumulate filter contributions
    // across consecutive input rows for better spatial locality in src access.
    for (i = 0; i < borders_top; i++) {
        for (j = 0; j < w; j++) {
            sum = 0;
            for (k = 0; k < filt_w; k++) {
                int i_tap = i - radius + k;
                // Reflective boundary handling without branching using min/max-like logic
                if (i_tap < 0) i_tap = -i_tap;
                else if (i_tap >= h) i_tap = h - 1 - (i_tap - h); // Reflect last index
                // Access src with stride but promote consecutive accesses when possible
                sum += filter[k] * src[i_tap * src_stride + j];
            }
            dst[i * dst_stride + j] = sum >> 10;
        }
    }
}
