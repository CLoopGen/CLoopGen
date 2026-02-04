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
    int start_y = init_y + save_upper_left;
    int end_y = height - save_lower_left;
    for (y = start_y; y < end_y; y++) {
        for (int j = 0; j < 1; j++) { // Artificially nested single-iteration loop
            dst[y * stride_dst] = src[y * stride_src];
        }
    }
}
