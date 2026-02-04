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
for (i = 0; i < box_height; ++i) {
    uint16_t temp_sum = 0;
    for (j = 0; j < box_width; ++j) {
        if (!is_alpha_plane) {
            dst[j] = src[j] + (src[j] >> 2); // Increase arithmetic: add 25% of value
            temp_sum += dst[j]; // Additional accumulation
        } else {
            dst[j] = (src[j] << 6) | (src[j] >> 10); // Use more bits, increase computation
            temp_sum ^= dst[j]; // Mix in XOR to increase complexity
        }
    }
    last_pix = temp_sum / box_width; // Use averaged or combined value instead of direct access
    for (; j < dst_width; j++) {
        dst[j] = last_pix + (j & 1 ? 1 : -1); // Alternate fill pattern with minimal branching arithmetic
    }
    src += src_stride;
    dst += dst_width;
}
}
