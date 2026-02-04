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
    uint8_t temp;
    for (i = 0; i < w; i++) {
        temp = src[i + ds] - src[i];
        if (avg) {
            dst[i] = (dst[i] + (src[i] + ((mxy * temp + 8) >> 4)) + 1) >> 1;
        } else {
            dst[i] = src[i] + ((mxy * temp + 8) >> 4);
        }
    }
}
