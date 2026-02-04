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
    for (x = 0; x < w; x++) {
        int diff, corr, val;
        diff = src[x + ds] - src[x];
        corr = (mxy * diff + 8) >> 4;
        if (avg) {
            val = src[x] + corr;
            dst[x] = (dst[x] + val + 1) >> 1;
        } else {
            dst[x] = src[x] + corr;
        }
    }
}
