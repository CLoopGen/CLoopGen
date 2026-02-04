#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short *extrema;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    ssize_t indices[256];
    for (i = 0; i <= 255; i++) {
        indices[i] = i;
    }
    for (i = 0; i <= 255; i++) {
        extrema[indices[i]] = 0;
    }
}
