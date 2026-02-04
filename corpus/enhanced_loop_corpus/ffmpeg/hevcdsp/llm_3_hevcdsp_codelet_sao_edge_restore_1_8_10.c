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
    // Variant 2: Strided access with reversed iteration order (backward traversal)
    for (y = height - save_lower_left - 1; y >= init_y + save_upper_left; y--) {
        *(dst + y * stride_dst) = *(src + y * stride_src);
    }
}
