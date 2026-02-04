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
    uint16_t prev_pix;
    for (i = 0; i < box_height; ++i) {
        prev_pix = is_alpha_plane ? (src[0] << 6) : src[0];
        for (j = 0; j < box_width; ++j) {
            uint16_t current_src = src[j];
            uint16_t scaled_src = is_alpha_plane ? (current_src << 6) : current_src;
            dst[j] = scaled_src;
            prev_pix = scaled_src;
        }
        last_pix = prev_pix;
        for (; j < dst_width; j++) {
            dst[j] = last_pix;
        }
        src += src_stride;
        dst += dst_width;
    }
}
