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
    // Variant 2: Indirect memory access using index mapping array (simulated via arithmetic)
    // Simulate indirect access by reversing the order of processing within box_width
    for (i = 0; i < box_height; ++i) {
        for (j = 0; j < box_width; ++j) {
            int rev_idx = box_width - 1 - j;  // reversed index for indirect-like access
            if (!is_alpha_plane) {
                dst[j] = src[rev_idx];
            } else {
                dst[j] = src[rev_idx] << 6;
            }
        }
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
