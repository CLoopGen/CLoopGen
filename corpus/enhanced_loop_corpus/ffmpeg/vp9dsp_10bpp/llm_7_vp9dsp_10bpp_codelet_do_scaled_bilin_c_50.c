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
    uint16_t prev_dst = 0;
    for (x = 0; x < w; x++) {
        uint16_t computed_val;
        computed_val = tmp_ptr[x] + ((my * (tmp_ptr[x + 64] - tmp_ptr[x]) + 8) >> 4);
        if (avg) {
            dst[x] = (prev_dst + computed_val + 1) >> 1;
        } else {
            dst[x] = computed_val;
        }
        prev_dst = dst[x]; // Introduce WAW and loop-carried dependency
    }
}
