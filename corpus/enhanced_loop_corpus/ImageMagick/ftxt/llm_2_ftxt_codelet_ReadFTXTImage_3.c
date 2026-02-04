#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float MagickFloatType;

typedef MagickFloatType Quantum;

extern int i;
extern int nExpCh;
extern long double chVals[64];
extern Quantum *q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // This variant accesses every second element in both chVals and q arrays.
    // It processes elements in a non-consecutive pattern, which can affect cache performance.
    for (i = 0; i < nExpCh; i += 2)
        q[i] = (char)chVals[i];
}
