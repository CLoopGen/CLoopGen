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
    for (x = 0; x < w; x++) {
        i = x;
        if (avg) {
            dst[i] = (dst[i] + (tmp_ptr[i] + ((my * (tmp_ptr[i + 64] - tmp_ptr[i]) + 8) >> 4)) + 1) >> 1;
        } else {
            dst[i] = (tmp_ptr[i] + ((my * (tmp_ptr[i + 64] - tmp_ptr[i]) + 8) >> 4));
        }
    }
}
