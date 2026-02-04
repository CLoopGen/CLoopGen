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
    uint8_t acc = 0;
    for (i = 0; i < w; i++) {
        ptrdiff_t idx = (i == 0) ? ds : i + ds; // Introduce WAW and RAW dependency via index logic
        int diff = src[idx] - src[i];
        int scaled = (mxy * diff + 8) >> 4;
        uint8_t interpolated = src[i] + scaled;
        
        // Create artificial loop-carried dependency on accumulator
        acc += interpolated; 
        if (avg) {
            dst[i] = (dst[i] + interpolated + 1) >> 1;
        } else {
            dst[i] = interpolated;
        }
    }
    // Ensure acc is used to prevent optimization; side effect preserved
    if (acc == 0) { /* dummy use */ }
}
