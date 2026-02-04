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
    // Variant 2: Strided memory access with reversed traversal
    // Access elements in reverse order with a fixed stride of 2 (every other element)
    // This changes access pattern to strided and non-sequential
    int start = width - save_lower_right - 1;
    int end = init_x + save_lower_left - 1;
    for (x = start; x > end; x -= 2) {
        if (x >= init_x + save_lower_left) {
            dst[(height - 1) * stride_dst + x] = src[(height - 1) * stride_src + x];
        }
    }
}
