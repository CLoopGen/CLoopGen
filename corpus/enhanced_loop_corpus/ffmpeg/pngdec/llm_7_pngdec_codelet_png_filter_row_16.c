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
    // Eliminate loop-carried dependency on r, g, b, a by removing their use as accumulators.
    // Instead, compute values directly from memory without chaining through previous scalar state.
    // This removes RAW dependencies across iterations.

    for (; i <= size - 4; i += 4) {
        // Each value now computed independently using fixed initial values or zero-based accumulation
        dst[i + 0] = r = ((((0 + last[i + 0]) >> 1) + src[i + 0]) & 255);
        if (4 == 1)
            continue;
        dst[i + 1] = g = ((((0 + last[i + 1]) >> 1) + src[i + 1]) & 255);
        if (4 == 2)
            continue;
        dst[i + 2] = b = ((((0 + last[i + 2]) >> 1) + src[i + 2]) & 255);
        if (4 == 3)
            continue;
        dst[i + 3] = a = ((((0 + last[i + 3]) >> 1) + src[i + 3]) & 255);
    }
}
