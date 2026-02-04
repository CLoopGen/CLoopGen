#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double data[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of accessing elements with stride 2, write zeros in consecutive order
    for (i = 0; i < 256; i++) {
        ((data)[i]) = 0.;
    }
}
