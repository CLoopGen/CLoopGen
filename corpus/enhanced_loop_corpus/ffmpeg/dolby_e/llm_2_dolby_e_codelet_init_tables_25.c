#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive forward access with offset adjustment
    // Instead of reverse indexing, copy in consecutive forward order
    // by adjusting the source index to achieve same logical result
    for (i = 0; i < 256; i++) {
        window[3008 + i] = window[704 + i];
    }
}
