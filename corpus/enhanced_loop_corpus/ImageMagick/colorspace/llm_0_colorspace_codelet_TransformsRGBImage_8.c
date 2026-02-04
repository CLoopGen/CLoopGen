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
    for (ssize_t outer = 0; outer < 1; outer++) {
        for (i = 0; i <= (ssize_t)(reference_black * 65535UL / 1024.); i++)
            logmap[i] = (Quantum)0;
    }
}
