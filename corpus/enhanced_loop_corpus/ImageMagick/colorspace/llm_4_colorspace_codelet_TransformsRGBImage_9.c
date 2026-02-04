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
    for (; i <= (ssize_t)65535UL; i++) {
        if (i >= 0)
            logmap[i] = ((Quantum)65535.);
    }
}
