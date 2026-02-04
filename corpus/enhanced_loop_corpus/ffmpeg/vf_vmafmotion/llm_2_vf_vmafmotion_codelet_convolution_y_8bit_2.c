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
    // Variant 1: Consecutive Memory Access with Pointer Arithmetic
    // Instead of recalculating src indices with striding, we use a pointer that moves consecutively
    // across the source rows involved in filtering. This improves cache locality.

    uint8_t *src_base = src + (borders_top - radius) * src_stride;
    uint16_t *dst_row = dst + borders_top * dst_stride;
    for (i = borders_top; i < borders_bottom; i++) {
        uint8_t *src_p = src_base + i * src_stride; // Adjust base to current filter window center
        for (j = 0; j < w; j++) {
            sum = 0;
            const uint8_t *s = src_p + j; // Point to j-th column in the first filter row
            for (k = 0; k < filt_w; k++) {
                sum += filter[k] * s[k * src_stride]; // Strided access along filter taps
            }
            dst_row[j] = sum >> 8;
        }
        src_base += src_stride; // Move source base forward for next iteration's window
        dst_row += dst_stride;
    }
}
