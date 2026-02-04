#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int my;
extern int avg;
extern uint8_t *tmp_ptr;
extern uint8_t *dst;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_loop_bound = (w + 3) / 4; // Process in chunks of 4
    for (int i = 0; i < outer_loop_bound; i++) {
        int base_x = i * 4;
        for (int j = 0; j < 4; j++) {
            x = base_x + j;
            if (x >= w) break;
            if (avg) {
                dst[x] = (dst[x] + (tmp_ptr[x] + ((my * (tmp_ptr[x + 64] - tmp_ptr[x]) + 8) >> 4)) + 1) >> 1;
            } else {
                dst[x] = (tmp_ptr[x] + ((my * (tmp_ptr[x + 64] - tmp_ptr[x]) + 8) >> 4));
            }
        }
    }
}
