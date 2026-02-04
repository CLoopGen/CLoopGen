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
for (x = 0; x < w && w > 32; x++) {
    int offset1 = x + 32;
    int offset2 = x + 64;
    int diff1 = tmp_ptr[offset1] - tmp_ptr[x];
    int diff2 = tmp_ptr[offset2] - tmp_ptr[offset1];
    int interp1 = (my * diff1 + 8) >> 4;
    int interp2 = (my * diff2 + 8) >> 4;
    int blended = (tmp_ptr[x] + interp1 + tmp_ptr[offset1] + interp2) >> 1;

    if (avg) {
        dst[x] = (dst[x] + blended + 1) >> 1;
    } else {
        dst[x] = blended;
    }
}
}
