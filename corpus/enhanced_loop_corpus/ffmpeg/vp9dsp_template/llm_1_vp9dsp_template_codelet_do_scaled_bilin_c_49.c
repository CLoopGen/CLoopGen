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
// Unroll the loop with depth 4 to reduce loop overhead
int remainder = w % 4;
int limit = w - remainder;

// Vectorized-like unrolling with depth 4
for (x = 0; x < limit; x += 4) {
    // Process 4 elements per iteration
    if (avg) {
        dst[x]   = (dst[x]   + (tmp_ptr[x]   + ((my * (tmp_ptr[x + 64] - tmp_ptr[x])   + 8) >> 4)) + 1) >> 1;
        dst[x+1] = (dst[x+1] + (tmp_ptr[x+1] + ((my * (tmp_ptr[x + 65] - tmp_ptr[x+1]) + 8) >> 4)) + 1) >> 1;
        dst[x+2] = (dst[x+2] + (tmp_ptr[x+2] + ((my * (tmp_ptr[x + 66] - tmp_ptr[x+2]) + 8) >> 4)) + 1) >> 1;
        dst[x+3] = (dst[x+3] + (tmp_ptr[x+3] + ((my * (tmp_ptr[x + 67] - tmp_ptr[x+3]) + 8) >> 4)) + 1) >> 1;
    } else {
        dst[x]   = (tmp_ptr[x]   + ((my * (tmp_ptr[x + 64] - tmp_ptr[x])   + 8) >> 4));
        dst[x+1] = (tmp_ptr[x+1] + ((my * (tmp_ptr[x + 65] - tmp_ptr[x+1]) + 8) >> 4));
        dst[x+2] = (tmp_ptr[x+2] + ((my * (tmp_ptr[x + 66] - tmp_ptr[x+2]) + 8) >> 4));
        dst[x+3] = (tmp_ptr[x+3] + ((my * (tmp_ptr[x + 67] - tmp_ptr[x+3]) + 8) >> 4));
    }
}

// Handle leftover elements
for (; x < w; x++) {
    if (avg) {
        dst[x] = (dst[x] + (tmp_ptr[x] + ((my * (tmp_ptr[x + 64] - tmp_ptr[x]) + 8) >> 4)) + 1) >> 1;
    } else {
        dst[x] = (tmp_ptr[x] + ((my * (tmp_ptr[x + 64] - tmp_ptr[x]) + 8) >> 4));
    }
}
}
