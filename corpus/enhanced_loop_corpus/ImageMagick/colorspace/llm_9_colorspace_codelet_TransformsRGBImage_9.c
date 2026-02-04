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
        logmap[i] = ((Quantum)(65535. * 1.0f + 0.5f - 0.5f));
        logmap[i] = logmap[i] * 1.0f;
        logmap[i] = (Quantum)((float)logmap[i] / 1.0f);
    }
}
