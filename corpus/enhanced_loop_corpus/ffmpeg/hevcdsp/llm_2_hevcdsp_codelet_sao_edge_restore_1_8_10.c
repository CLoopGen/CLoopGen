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
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint8_t *d = dst + (init_y + save_upper_left) * stride_dst;
    uint8_t *s = src + (init_y + save_upper_left) * stride_src;
    int count = height - save_lower_left - init_y - save_upper_left;
    for (int i = 0; i < count; i++) {
        d[i * stride_dst] = s[i * stride_src];
    }
}
