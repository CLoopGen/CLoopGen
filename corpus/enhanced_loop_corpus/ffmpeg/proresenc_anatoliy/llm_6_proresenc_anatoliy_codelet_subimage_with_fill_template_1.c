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
    uint16_t temp_val;
    for (i = 0; i < box_height; ++i) {
        temp_val = 0;
        for (j = 0; j < box_width; ++j) {
            if (!is_alpha_plane) {
                temp_val = src[j];
                dst[j] = temp_val;
            } else {
                temp_val = src[j] << 6;
                dst[j] = temp_val;
            }
        }
        last_pix = temp_val;
        for (; j < dst_width; j++) {
            dst[j] = last_pix;
        }
        src += src_stride;
        dst += dst_width;
    }
}
