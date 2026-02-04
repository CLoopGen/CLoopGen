#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse order, then fill gaps)
    for (i = 62; i >= 0; i -= 2) {
        int idx = i;
        left[idx] = ((64 - (idx + 1)) * left[-1] + (idx + 1) * left[63] + 32) >> 6;
    }
    for (i = 63; i >= 0; i -= 2) {
        int idx = i;
        if (idx == 63) continue; // skip out-of-bounds if i=63
        left[idx] = ((64 - (idx + 1)) * left[-1] + (idx + 1) * left[63] + 32) >> 6;
    }
}
