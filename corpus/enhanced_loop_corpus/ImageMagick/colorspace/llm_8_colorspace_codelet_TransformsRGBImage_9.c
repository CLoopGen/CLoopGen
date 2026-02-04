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
    ssize_t step = 2;
    for (; i <= (ssize_t)65535UL; i += step) {
        logmap[i] = ((Quantum)65535.);
        if (i + 1 <= 65535UL) {
            logmap[i + 1] = ((Quantum)65535.);
        }
    }
}
