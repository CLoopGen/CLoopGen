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
    // Variant 2: Reverse consecutive memory access
    // This variant traverses the arrays from the last element to the first,
    // maintaining consecutive access but in reverse order.
    for (i = nExpCh - 1; i >= 0; i--)
        q[i] = (char)chVals[i];
}
