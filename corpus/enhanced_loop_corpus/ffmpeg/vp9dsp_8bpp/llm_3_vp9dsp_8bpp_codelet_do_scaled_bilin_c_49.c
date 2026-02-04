#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int my;
extern int avg;
extern uint8_t *tmp_ptr;
extern uint8_t *dst;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive two-element prefetch pattern with local accumulation
    // Simulates improved spatial locality by accessing adjacent elements together
    for (x = 0; x < w - 1; x += 2) {
        // Process two consecutive elements at once to improve cache utilization
        int val1, val2;

        val1 = tmp_ptr[x] + ((my * (tmp_ptr[x + 64] - tmp_ptr[x]) + 8) >> 4);
        val2 = tmp_ptr[x+1] + ((my * (tmp_ptr[x + 65] - tmp_ptr[x+1]) + 8) >> 4);

        if (avg) {
            dst[x]   = (dst[x]   + val1 + 1) >> 1;
            dst[x+1] = (dst[x+1] + val2 + 1) >> 1;
        } else {
            dst[x]   = val1;
            dst[x+1] = val2;
        }
    }

    // Handle remaining element if width is odd
    if (x < w) {
        int val = tmp_ptr[x] + ((my * (tmp_ptr[x + 64] - tmp_ptr[x]) + 8) >> 4);
        if (avg) {
            dst[x] = (dst[x] + val + 1) >> 1;
        } else {
            dst[x] = val;
        }
    }
}
