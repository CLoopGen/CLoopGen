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
    for (x = 0; x < w; x += 2) {
        for (int offset = 0; offset < 2 && (x + offset) < w; offset++) {
            int idx = x + offset;
            if (avg) {
                dst[idx] = (dst[idx] + (src[idx] + ((mxy * (src[idx + ds] - src[idx]) + 8) >> 4)) + 1) >> 1;
            } else {
                dst[idx] = (src[idx] + ((mxy * (src[idx + ds] - src[idx]) + 8) >> 4));
            }
        }
    }
}
