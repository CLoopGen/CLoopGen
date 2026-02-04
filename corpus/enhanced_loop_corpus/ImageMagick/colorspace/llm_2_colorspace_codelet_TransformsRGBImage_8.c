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
    // Variant 1: Consecutive memory access with unrolling factor of 2
    // This accesses logmap in consecutive locations, reducing stride and improving cache locality
    ssize_t upper_bound = (ssize_t)(reference_black * 65535UL / 1024.);
    for (i = 0; i <= upper_bound; i += 2) {
        logmap[i] = (Quantum)0;
        if (i + 1 <= upper_bound) {
            logmap[i + 1] = (Quantum)0;
        }
    }
}
