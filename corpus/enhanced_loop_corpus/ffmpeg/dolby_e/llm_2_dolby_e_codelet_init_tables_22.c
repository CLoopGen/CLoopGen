#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Access pattern: every second element in decreasing order, writing to two different strided regions
    for (i = 0; i < 256; i += 2) {
        window[2304 + i] = window[1663 - i];
        window[1152 + i] = window[1663 - i];
    }
}
