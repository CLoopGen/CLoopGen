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
    Quantum temp;
    for (i = 0; i < nExpCh; i++) {
        temp = (char)chVals[i];
        q[i] = temp;
    }
}
