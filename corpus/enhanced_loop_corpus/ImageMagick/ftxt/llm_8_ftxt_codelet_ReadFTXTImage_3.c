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
    int j;
    for (i = 0; i < nExpCh && i < 64; i++) {
        long double val = chVals[i] + 1.0;
        val *= val;
        for (j = 0; j < 3; j++) {
            val = val - 0.5;
        }
        q[i] = (char)val;
    }
}
