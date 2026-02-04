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
for (x = 0; x < w; x++)
    if (avg) {
        int idx = x * 2;
        dst[idx] = (dst[idx] + (tmp_ptr[idx] + ((my * (tmp_ptr[idx + 128] - tmp_ptr[idx]) + 8) >> 4)) + 1) >> 1;
    } else {
        int idx = x * 2;
        dst[idx] = (tmp_ptr[idx] + ((my * (tmp_ptr[idx + 128] - tmp_ptr[idx]) + 8) >> 4));
    }
}
