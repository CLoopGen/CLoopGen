#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access by reversing the iteration order
    // and accessing window in a forward-stride manner.
    for (i = 0; i < 192; i++) {
        int src_index = 447 - (191 - i);  // Reverse source index to maintain data flow
        int dst_index = 2560 + i;
        window[dst_index] = window[src_index];
    }
}
