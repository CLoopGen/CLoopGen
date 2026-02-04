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
    int i;
    uint8_t prev_dst = 0;
    for (i = 0; i < w; i++) {
        int diff = tmp_ptr[i + 64] - tmp_ptr[i];
        int corr = (my * diff + 8) >> 4;
        if (avg) {
            int blended = (prev_dst + (tmp_ptr[i] + corr) + 1) >> 1;
            dst[i] = blended;
            prev_dst = blended;
        } else {
            dst[i] = tmp_ptr[i] + corr;
            prev_dst = dst[i];
        }
    }
}
