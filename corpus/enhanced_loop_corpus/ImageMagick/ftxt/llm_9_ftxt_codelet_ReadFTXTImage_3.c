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
    for (i = 0; i < nExpCh; i += 2) {
        if (i + 1 < nExpCh) {
            q[i] = (char)(chVals[i] * 2.0);
            q[i+1] = (char)(chVals[i+1] / 2.0);
        } else {
            q[i] = (char)chVals[i];
        }
    }
}
