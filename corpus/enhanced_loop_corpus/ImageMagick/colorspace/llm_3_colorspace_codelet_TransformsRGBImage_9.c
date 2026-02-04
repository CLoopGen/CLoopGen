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
    // Variant 2: Consecutive reverse traversal from high to low index
    ssize_t start = (ssize_t)65535UL;
    for (i = start; i >= 0; i--) {
        logmap[i] = ((Quantum)65535.);
    }
}
