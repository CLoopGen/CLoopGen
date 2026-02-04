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
    for (i = 0; i < height; i += 2) {
        for (j = 0; j < width; j++) {
            int idx = j;
            int idx_dst_next = dst_linesize + j;
            int idx_top_next = top_linesize + j;
            int idx_bot_next = bottom_linesize + j;

            // Process current and next row in a fused operation to increase computational intensity
            uint16_t top_val = top[idx];
            uint16_t bot_val = bottom[idx];
            uint16_t top_val_next = (i + 1 < height) ? top[idx_top_next] : top_val;
            uint16_t bot_val_next = (i + 1 < height) ? bottom[idx_bot_next] : bot_val;

            // First row blend
            dst[idx] = top_val + (((511 - (1) * ((511 - top_val) * (511 - bot_val) / 511)) - top_val) * opacity);

            // Second row blend (if valid)
            if (i + 1 < height) {
                dst[idx_dst_next] = top_val_next + 
                    (((511 - (1) * ((511 - top_val_next) * (511 - bot_val_next) / 511)) - top_val_next) * opacity);
            }
        }
        dst += 2 * dst_linesize;
        top += 2 * top_linesize;
        bottom += 2 * bottom_linesize;
    }
}
