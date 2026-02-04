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
    uint16_t temp_val;
    for (x = 0; x < w; x++) {
        temp_val = tmp_ptr[x];
        if (avg) {
            dst[x] = (dst[x] + (temp_val + ((my * (tmp_ptr[x + 64] - temp_val) + 8) >> 4)) + 1) >> 1;
        } else {
            dst[x] = temp_val + ((my * (tmp_ptr[x + 64] - temp_val) + 8) >> 4);
        }
    }
}
