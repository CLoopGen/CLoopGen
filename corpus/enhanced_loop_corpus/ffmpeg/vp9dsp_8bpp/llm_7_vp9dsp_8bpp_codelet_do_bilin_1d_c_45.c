#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern ptrdiff_t ds;
extern int mxy;
extern int avg;
extern uint8_t *dst;
extern  uint8_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    uint8_t prev_dst = 0;
    for (i = 0; i < w; i++) {
        uint8_t prediction = (i == 0) ? prev_dst : dst[i - 1];
        int adjusted_src = src[i] + ((mxy * (src[i + ds] - src[i]) + 8) >> 4);
        if (avg) {
            dst[i] = (prediction + adjusted_src + 1) >> 1;
        } else {
            dst[i] = adjusted_src;
        }
        prev_dst = dst[i];
    }
}
