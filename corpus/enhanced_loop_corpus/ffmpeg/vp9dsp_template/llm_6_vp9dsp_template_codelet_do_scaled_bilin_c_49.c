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
    uint8_t temp_val;
    for (i = 0; i < w; i++) {
        temp_val = tmp_ptr[i];
        if (avg) {
            dst[i] = (dst[i] + (temp_val + ((my * (tmp_ptr[i + 64] - temp_val) + 8) >> 4)) + 1) >> 1;
        } else {
            dst[i] = temp_val + ((my * (tmp_ptr[i + 64] - temp_val) + 8) >> 4);
        }
    }
}
