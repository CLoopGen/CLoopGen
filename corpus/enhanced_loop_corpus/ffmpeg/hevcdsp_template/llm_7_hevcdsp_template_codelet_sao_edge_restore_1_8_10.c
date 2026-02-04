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
extern int height;
extern int save_upper_left;
extern int save_lower_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = init_y + save_upper_left; y < height - save_lower_left; y++) {
        if (y > init_y + save_upper_left) {
            dst[(y - 1) * stride_dst] = src[y * stride_src]; // Introduce WAW and WAR dependency: write-before-write and write-after-read
        }
        dst[y * stride_dst] = src[y * stride_src];
    }
    if (height - save_lower_left > init_y + save_upper_left) {
        dst[(height - save_lower_left - 1) * stride_dst] = src[(height - save_lower_left - 1) * stride_src];
    }
}
