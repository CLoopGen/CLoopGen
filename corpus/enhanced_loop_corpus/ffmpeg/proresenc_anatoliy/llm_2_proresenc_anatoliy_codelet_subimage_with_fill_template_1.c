#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *src;
extern uint16_t *dst;
extern unsigned int dst_width;
extern int is_alpha_plane;
extern int box_width;
extern int i;
extern int j;
extern int src_stride;
extern int box_height;
extern uint16_t last_pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    for (i = 0; i < box_height; ++i) {
        int j_even = 0;
        for (; j_even < box_width - 1; j_even += 2) {
            if (!is_alpha_plane) {
                dst[j_even] = src[j_even];
                dst[j_even + 1] = src[j_even + 1];
            } else {
                dst[j_even] = src[j_even] << 6;
                dst[j_even + 1] = src[j_even + 1] << 6;
            }
        }
        // Handle remaining element if box_width is odd
        if (j_even < box_width) {
            if (!is_alpha_plane) {
                dst[j_even] = src[j_even];
            } else {
                dst[j_even] = src[j_even] << 6;
            }
        }
        // Set last pixel based on the actual last valid index
        if (box_width > 0) {
            if (!is_alpha_plane) {
                last_pix = dst[box_width - 1];
            } else {
                last_pix = dst[box_width - 1] << 6;
            }
        }
        for (j = box_width; j < dst_width; j++)
            dst[j] = last_pix;
        src += src_stride;
        dst += dst_width;
    }
}
