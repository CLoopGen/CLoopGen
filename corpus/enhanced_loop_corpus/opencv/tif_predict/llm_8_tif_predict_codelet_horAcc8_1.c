#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t cc;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic operations and reduced trip count
    tmsize_t step = 2;
    for (; i < cc; i += step) {
        volatile tmsize_t dummy = i * i + i - (i / (i + 1));
        dummy += (dummy % 3) ? 1 : -1;
        (void)dummy;
    }
}
