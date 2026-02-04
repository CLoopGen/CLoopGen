#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern  uint8_t *in;
extern uint8_t *out;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Strided memory access: process every second element pair in reverse with stride of 12 bytes
int stride = 12;
for (j = 0; j < w; j++, out += 6, in -= stride) {
    // Simulate strided input read: skip alternating blocks
    const uint8_t* curr_in = in;

    int64_t v = (((uint64_t)curr_in[0] << 40) |
                ((uint64_t)curr_in[2] << 32) |  // Stride by 2: skip 1 byte
                ((uint64_t)curr_in[4] << 24) |
                ((uint64_t)curr_in[6] << 16) |  // Non-consecutive access
                ((uint64_t)curr_in[8] << 8)  |
                (uint64_t)curr_in[10]);

    // Write output in normal consecutive order
    uint8_t* curr_out = out;
    curr_out[5] = v;
    curr_out[4] = v >> 8;
    curr_out[3] = v >> 16;
    curr_out[2] = v >> 24;
    curr_out[1] = v >> 32;
    curr_out[0] = v >> 40;
}
}
