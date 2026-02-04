#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride_dst;
extern ptrdiff_t stride_src;
extern int y;
extern uint8_t *dst;
extern uint8_t *src;
extern int init_y;
extern int width;
extern int height;
extern int save_upper_right;
extern int save_lower_right;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t offset;
    for (y = init_y + save_upper_right; y < height - save_lower_right; y++) {
        if ((y & 1) == 0) {
            offset = y * stride_dst + width - 1;
            dst[offset] = src[y * stride_src + width - 1];
        }
    }
}
