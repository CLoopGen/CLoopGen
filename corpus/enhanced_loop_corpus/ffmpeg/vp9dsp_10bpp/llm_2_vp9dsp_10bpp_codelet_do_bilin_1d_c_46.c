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
for (x = 0; x < w; x += 2)
    if (avg) {
        dst[x] = (dst[x] + (src[x] + ((mxy * (src[x + ds] - src[x]) + 8) >> 4)) + 1) >> 1;
        if (x + 1 < w) {
            dst[x + 1] = (dst[x + 1] + (src[x + 1] + ((mxy * (src[x + 1 + ds] - src[x + 1]) + 8) >> 4)) + 1) >> 1;
        }
    } else {
        dst[x] = (src[x] + ((mxy * (src[x + ds] - src[x]) + 8) >> 4));
        if (x + 1 < w) {
            dst[x + 1] = (src[x + 1] + ((mxy * (src[x + 1 + ds] - src[x + 1]) + 8) >> 4));
        }
    }
}
