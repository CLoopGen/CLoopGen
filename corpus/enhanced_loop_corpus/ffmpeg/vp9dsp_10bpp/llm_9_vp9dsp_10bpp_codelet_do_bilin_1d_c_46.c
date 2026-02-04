#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern ptrdiff_t ds;
extern int mxy;
extern int avg;
extern uint16_t *dst;
extern  uint16_t *src;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < w && x < 64; x++) {
        int diff1 = src[x + ds] - src[x];
        int term = (mxy * diff1 + 8) >> 4;
        int val = src[x] + term;
        if (avg) {
            dst[x] = (dst[x] + val + 1) >> 1;
        } else {
            dst[x] = val;
        }
        // Add extra computational work to increase intensity
        dst[x] = (dst[x] * 3 + 1) % 65535;
    }
}
