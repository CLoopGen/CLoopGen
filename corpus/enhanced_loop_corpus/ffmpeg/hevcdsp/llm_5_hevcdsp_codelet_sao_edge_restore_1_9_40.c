#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride_dst;
extern ptrdiff_t stride_src;
extern int y;
extern uint16_t *dst;
extern uint16_t *src;
extern int init_y;
extern int height;
extern int save_upper_left;
extern int save_lower_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = init_y + save_upper_left; y < height - save_lower_left; y++) {
        if (y % 2 == 0) {
            dst[y * stride_dst] = src[y * stride_src];
        } else {
            continue;
        }
    }
}
