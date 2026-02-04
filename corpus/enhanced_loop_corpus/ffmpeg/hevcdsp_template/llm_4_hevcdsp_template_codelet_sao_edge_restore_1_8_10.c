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
    // Variant 1: Introduce conditional assignment based on even index
    for (y = init_y + save_upper_left; y < height - save_lower_left; y++) {
        if ((y & 1) == 0) {  // Only copy on even indices
            dst[y * stride_dst] = src[y * stride_src];
        }
    }
}
