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
for (x = 0; x < w; x++) {
    int diff = tmp_ptr[x + 64] - tmp_ptr[x];
    int interpolated = (my * diff + 8) >> 4;
    int val = tmp_ptr[x] + interpolated;
    if (avg) {
        dst[x] = (dst[x] + val + 1) >> 1;
    } else {
        dst[x] = val;
    }
}
}
