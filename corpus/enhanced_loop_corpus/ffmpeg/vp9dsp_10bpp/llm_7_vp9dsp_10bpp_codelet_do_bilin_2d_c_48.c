#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int w;
extern int my;
extern int avg;
extern uint16_t *tmp_ptr;
extern uint16_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    uint16_t prev_dst = dst[0];
    for (i = 0; i < w; i++) {
        uint16_t base = tmp_ptr[i];
        uint16_t offset_val = tmp_ptr[i + 64];
        int delta = offset_val - base;
        int correction = (my * delta + 8) >> 4;
        uint16_t new_val = base + correction;
        if (avg) {
            uint16_t smoothed = (prev_dst + new_val + 1) >> 1;
            dst[i] = smoothed;
            prev_dst = smoothed; 
        } else {
            dst[i] = new_val;
            prev_dst = new_val;
        }
    }
}
