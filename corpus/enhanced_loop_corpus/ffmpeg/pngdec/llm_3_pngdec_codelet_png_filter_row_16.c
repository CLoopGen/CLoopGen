#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern uint8_t *last;
extern int size;
extern int i;
extern int r;
extern int g;
extern int b;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step size of 4 (structure of arrays style), processing one component at a time across multiple elements
    // Assume input data is laid out as four parallel streams: R, G, B, A each of length ~size/4
    int limit = size / 4;
    for (int j = 0; j < limit; ++j) {
        int idx = j * 4;
        dst[idx + 0] = r = ((((r + last[idx + 0]) >> 1) + src[idx + 0]) & 255);
        dst[idx + 1] = g = ((((g + last[idx + 1]) >> 1) + src[idx + 1]) & 255);
        dst[idx + 2] = b = ((((b + last[idx + 2]) >> 1) + src[idx + 2]) & 255);
        dst[idx + 3] = a = ((((a + last[idx + 3]) >> 1) + src[idx + 3]) & 255);
    }
    i = limit * 4; // update global index to reflect progress
}
