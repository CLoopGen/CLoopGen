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
        int temp_src = src[x];
        int temp_pred = (mxy * (src[x + ds] - temp_src) + 8) >> 4;
        int combined = temp_src + temp_pred;
        dst[x] = avg ? ((dst[x] + combined + 1) >> 1) : combined;
    }
}
