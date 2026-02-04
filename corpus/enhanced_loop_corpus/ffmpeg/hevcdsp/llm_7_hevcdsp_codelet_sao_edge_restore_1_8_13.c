#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride_dst;
extern ptrdiff_t stride_src;
extern int x;
extern uint8_t *dst;
extern uint8_t *src;
extern int init_x;
extern int width;
extern int height;
extern int save_lower_right;
extern int save_lower_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i = init_x + save_lower_left;
    int limit = width - save_lower_right;
    int idx_dst = (height - 1) * stride_dst + i;
    int idx_src = (height - 1) * stride_src + i;
    for (; i < limit; i++) {
        dst[idx_dst] = src[idx_src];
        idx_dst += 1;
        idx_src += 1;
    }
}
