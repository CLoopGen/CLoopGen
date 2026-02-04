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
    if (!avg) {
        for (x = 0; x < w; x++) {
            dst[x] = src[x] + ((mxy * (src[x + ds] - src[x]) + 8) >> 4);
        }
    } else {
        for (x = 0; x < w; x++) {
            dst[x] = (dst[x] + (src[x] + ((mxy * (src[x + ds] - src[x]) + 8) >> 4)) + 1) >> 1;
        }
    }
}
