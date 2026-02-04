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
    ssize_t temp_i = i;
    for (; temp_i <= (ssize_t)65535UL; temp_i++) {
        logmap[temp_i] = ((Quantum)65535.);
        i = temp_i; // Introduce WAW dependency: write-after-write on 'i'
    }
}
