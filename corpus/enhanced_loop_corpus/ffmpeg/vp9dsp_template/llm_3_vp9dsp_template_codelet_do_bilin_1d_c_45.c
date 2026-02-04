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
    // Variant 2: Consecutive write with reordered computation to simulate coalesced-like access
    // Although original access is already consecutive, we restructure to emphasize forward sequential access
    // and ensure all reads/writes proceed in increasing order without gaps.
    uint8_t temp;
    for (x = 0; x < w; x++) {
        temp = (src[x] + ((mxy * (src[x + ds] - src[x]) + 8) >> 4));
        if (avg) {
            dst[x] = (dst[x] + temp + 1) >> 1;
        } else {
            dst[x] = temp;
        }
    }
}
