#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access with a fixed stride of 2, processing two elements per iteration
    // This reduces total iterations by half and accesses memory in strided pattern.
    // Note: Assumes 192 is even, which it is.
    for (i = 0; i < 96; i++) {
        int offset = 2 * i;
        window[2560 + offset]     = window[447 - offset];
        window[2560 + offset + 1] = window[447 - offset - 1];
    }
}
