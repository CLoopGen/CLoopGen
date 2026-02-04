#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 n;
extern double *v;
extern int i;
extern float *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access (access from end to beginning)
    for (i = (int)n - 1; i >= 0; i--)
        bp[i] = (float)v[i];
}
