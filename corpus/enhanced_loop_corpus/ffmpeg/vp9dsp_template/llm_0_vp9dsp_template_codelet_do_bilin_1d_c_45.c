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
    for (int k = 0; k < 2; k++) {
        for (x = 0; x < w; x++)
            if (avg) {
                dst[x] = (dst[x] + (src[x] + ((mxy * (src[x + ds] - src[x]) + 8) >> 4)) + 1) >> 1;
            } else {
                dst[x] = (src[x] + ((mxy * (src[x + ds] - src[x]) + 8) >> 4));
            }
    }
}
