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
    for (x = 0; x < w; x++) {
        int diff = src[x + ds] - src[x];
        int pred = (mxy * diff + 8) >> 4;
        int val = src[x] + pred;
        if (avg) {
            dst[x] = (dst[x] + val + 1) >> 1;
        } else {
            dst[x] = val;
        }
    }
}
