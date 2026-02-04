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
    ssize_t j;
    for (j = i; j <= (ssize_t)65535UL; j++)
        logmap[j] = ((Quantum)65535.);
}
