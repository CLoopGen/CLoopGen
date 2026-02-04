#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float MagickFloatType;

typedef MagickFloatType Quantum;

extern ssize_t i;
extern Quantum *logmap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 4
    for (; i <= (ssize_t)65535UL; i += 4) {
        logmap[i] = ((Quantum)65535.);
        if (i + 1 <= (ssize_t)65535UL) logmap[i + 1] = ((Quantum)65535.);
        if (i + 2 <= (ssize_t)65535UL) logmap[i + 2] = ((Quantum)65535.);
        if (i + 3 <= (ssize_t)65535UL) logmap[i + 3] = ((Quantum)65535.);
    }
}
