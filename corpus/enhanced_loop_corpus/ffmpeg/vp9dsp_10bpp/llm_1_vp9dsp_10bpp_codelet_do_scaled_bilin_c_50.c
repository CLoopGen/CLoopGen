#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int my;
extern int avg;
extern uint16_t *tmp_ptr;
extern uint16_t *dst;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_loop_count = (w + 31) >> 5; // ceil(w / 32)
    for (int block = 0; block < outer_loop_count; block++) {
        int start_x = block << 5; // block * 32
        int end_x = (start_x + 32 < w) ? start_x + 32 : w;
        for (x = start_x; x < end_x; x++) {
            if (avg) {
                dst[x] = (dst[x] + (tmp_ptr[x] + ((my * (tmp_ptr[x + 64] - tmp_ptr[x]) + 8) >> 4)) + 1) >> 1;
            } else {
                dst[x] = (tmp_ptr[x] + ((my * (tmp_ptr[x + 64] - tmp_ptr[x]) + 8) >> 4));
            }
        }
    }
}
