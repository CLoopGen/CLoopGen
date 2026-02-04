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
    // Variant 2: Decreased effective nesting depth by unrolling the loop (partial unroll with step 2)
    // This reduces the number of iterations and removes nested structure entirely
    int start = init_y + save_upper_right;
    int end = height - save_lower_right;
    int i = start;

    // Handle even number of iterations with unrolling factor 2
    for (; i <= end - 2; i += 2) {
        dst[i * stride_dst + width - 1] = src[i * stride_src + width - 1];
        dst[(i+1) * stride_dst + width - 1] = src[(i+1) * stride_src + width - 1];
    }

    // Handle remaining element if any
    if (i < end) {
        dst[i * stride_dst + width - 1] = src[i * stride_src + width - 1];
    }
}
