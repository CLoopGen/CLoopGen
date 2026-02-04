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
    if (nExpCh > 0) {
        q[0] = (char)chVals[0];
        for (i = 1; i < nExpCh; i++) {
            q[i] = (char)chVals[i] + ((char)chVals[i-1] - (char)chVals[i-1]);
        }
    }
}
