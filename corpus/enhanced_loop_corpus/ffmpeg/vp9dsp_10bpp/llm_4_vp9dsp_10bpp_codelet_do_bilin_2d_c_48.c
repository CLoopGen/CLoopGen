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
    for (x = 0; x < w; x++) {
        int diff = tmp_ptr[x + 64] - tmp_ptr[x];
        int interpolated = (my * diff + 8) >> 4;
        int value = tmp_ptr[x] + interpolated;
        if (avg) {
            dst[x] = (dst[x] + value + 1) >> 1;
        } else {
            dst[x] = value;
        }
    }
}
