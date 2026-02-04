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
    for (x = 0; x < w; x++) {
        int diff = src[x + ds] - src[x];
        int term = (mxy * diff + 8) >> 4;
        dst[x] = avg ? ((dst[x] + src[x] + term + 1) >> 1) : (src[x] + term);
    }
}
