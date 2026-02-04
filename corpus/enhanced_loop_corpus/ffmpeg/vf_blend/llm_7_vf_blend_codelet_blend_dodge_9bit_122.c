#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t top_linesize;
extern ptrdiff_t bottom_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern  uint16_t *top;
extern  uint16_t *bottom;
extern uint16_t *dst;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < height; i++) {
        uint16_t *current_dst = dst;
        uint16_t *current_top = top;
        uint16_t *current_bottom = bottom;

        for (j = 0; j < width; j++) {
            uint16_t t = current_top[j];
            uint16_t b = current_bottom[j];
            uint16_t comp;

            // Introduce artificial dependency: use previous result to influence current comp (WAW-like, but within same iteration)
            // This creates an intra-iteration dependency chain across j
            if (j == 0) {
                comp = (t == 511) ? 511 : ((b << 9) / (511 - t) > 511 ? 511 : (b << 9) / (511 - t));
            } else {
                // Use a function of previous comp to conditionally clamp current value (introduces RAW dependency on prior j)
                int threshold = (current_dst[j-1] & 0xFF); // Use low byte of previous output
                ptrdiff_t raw_comp = (b << 9) / ((511 - t) ? (511 - t) : 1);
                comp = (raw_comp > threshold) ? threshold : raw_comp;
                if (comp > 511) comp = 511;
            }

            current_dst[j] = t + (comp - t) * opacity;
        }

        // Remove immediate pointer update at end of loop body; instead, update in strides using index arithmetic (reduces WAW on pointer vars per iteration)
        dst = (uint16_t *)((char *)dst + dst_linesize * sizeof(uint16_t));
        top = (uint16_t *)((char *)top + top_linesize * sizeof(uint16_t));
        bottom = (uint16_t *)((char *)bottom + bottom_linesize * sizeof(uint16_t));
    }
}
