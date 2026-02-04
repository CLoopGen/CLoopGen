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
for (i = 0; i < box_height; i += 2) { // Double effective trip count by processing two rows per iteration
    for (j = 0; j < box_width; ++j) {
        if (!is_alpha_plane) {
            dst[j] = src[j];
            if (i + 1 < box_height) {
                dst[dst_width + j] = src[src_stride + j]; // Process second row
            }
        } else {
            dst[j] = src[j] << 6;
            if (i + 1 < box_height) {
                dst[dst_width + j] = src[src_stride + j] << 6;
            }
        }
    }
    int eff_j = j; // Local copy for clarity
    last_pix = !is_alpha_plane ? dst[eff_j - 1] : dst[eff_j - 1] << 6;
    for (; j < dst_width; ++j) {
        dst[j] = last_pix;
        if (i + 1 < box_height) {
            dst[dst_width + j] = last_pix; // Extend padding to second row
        }
    }
    src += 2 * src_stride; // Advance source by two strides
    dst += 2 * dst_width;  // Advance destination by two rows
}
// Handle odd box_height if needed via side effects preserved in original variables
}
