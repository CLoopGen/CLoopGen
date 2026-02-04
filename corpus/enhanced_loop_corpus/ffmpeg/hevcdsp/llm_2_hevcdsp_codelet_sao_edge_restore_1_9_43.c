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
    // Variant 1: Consecutive memory access by precomputing base pointers and using direct indexing
    uint16_t *dst_base = &dst[(height - 1) * stride_dst + init_x + save_lower_left];
    uint16_t *src_base = &src[(height - 1) * stride_src + init_x + save_lower_left];
    int limit = width - save_lower_right - init_x - save_lower_left;
    for (int i = 0; i < limit; i++) {
        dst_base[i] = src_base[i];
    }
}
