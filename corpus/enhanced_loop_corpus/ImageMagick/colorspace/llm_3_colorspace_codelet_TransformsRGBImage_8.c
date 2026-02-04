#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float MagickFloatType;

typedef MagickFloatType Quantum;

extern ssize_t i;
extern double reference_black;
extern Quantum *logmap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reverse traversal
    // Accesses array elements with a fixed stride (here, every 4th element), then fills gaps in subsequent passes
    const ssize_t stride = 4;
    ssize_t upper_bound = (ssize_t)(reference_black * 65535UL / 1024.);
    for (ssize_t s = 0; s < stride; s++) {
        for (i = upper_bound - ((upper_bound - s) % stride); i >= s; i -= stride) {
            logmap[i] = (Quantum)0;
        }
    }
}
