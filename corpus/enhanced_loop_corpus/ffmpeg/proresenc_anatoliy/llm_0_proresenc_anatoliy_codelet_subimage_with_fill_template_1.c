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
    j = 0;
    if (!is_alpha_plane) {
        for (; j < box_width; ++j) {
            dst[j] = src[j];
        }
        last_pix = dst[j - 1];
    } else {
        for (; j < box_width; ++j) {
            dst[j] = src[j] << 6;
        }
        last_pix = dst[j - 1] << 6;
    }
    for (; j < dst_width; j++)
        dst[j] = last_pix;
    src += src_stride;
    dst += dst_width;
}
}
