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
    uint16_t temp;
    for (x = init_x + save_lower_left; x < width - save_lower_right; x++) {
        temp = src[(height - 1) * stride_src + x];
        dst[(height - 1) * stride_dst + x] = temp;
    }
}
