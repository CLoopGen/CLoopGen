#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short shift;
extern int off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_off = off;
    short local_shift = 0;
    for (shift = 0; ((local_off) >= 0 ? (local_off) : (-local_off)) <= 16383; local_shift++) {
        local_off <<= 1; // Replace multiplication with bit-shift, same effect
        shift = local_shift; // RAW dependency: read-after-write on local_shift to update shift
    }
    off = local_off; // Eliminate loop-carried dependency on global 'off' until end
}
