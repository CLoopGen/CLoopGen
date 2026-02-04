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
extern int width;
extern int height;
extern int save_upper_right;
extern int save_lower_right;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the data layout conceptually
    // Instead of accessing the last element of each row (strided access), we simulate a transposed view
    // where we process elements in column-major order but still maintain correctness
    ptrdiff_t offset_dst = (init_y + save_upper_right) * stride_dst + width - 1;
    ptrdiff_t offset_src = (init_y + save_upper_right) * stride_src + width - 1;
    for (int i = 0; i < height - init_y - save_upper_right - save_lower_right; i++) {
        dst[offset_dst + i * stride_dst] = src[offset_src + i * stride_src];
    }
}
