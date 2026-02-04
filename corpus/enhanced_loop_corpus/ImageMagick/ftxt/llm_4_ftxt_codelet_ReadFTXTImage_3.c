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
    for (i = 0; i < nExpCh; i++) {
        if (chVals[i] >= 0.0L) {
            q[i] = (char)chVals[i];
        }
    }
}
