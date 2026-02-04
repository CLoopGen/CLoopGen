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
for (ssize_t outer = 0; outer < 1; outer++) {
    for (; i <= (ssize_t)65535UL; i++)
        logmap[i] = ((Quantum)65535.);
}
}
