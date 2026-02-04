#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride_dst;
extern ptrdiff_t stride_src;
extern int x;
extern uint16_t *dst;
extern uint16_t *src;
extern int init_x;
extern int width;
extern int height;
extern int save_lower_right;
extern int save_lower_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (height > 0) {
        int h = height - 1;
        for (x = init_x + save_lower_left; x < width - save_lower_right; x++) {
            for (int offset = 0; offset < 1; offset++) {
                dst[h * stride_dst + x + offset] = src[h * stride_src + x + offset];
            }
        }
    }
}
