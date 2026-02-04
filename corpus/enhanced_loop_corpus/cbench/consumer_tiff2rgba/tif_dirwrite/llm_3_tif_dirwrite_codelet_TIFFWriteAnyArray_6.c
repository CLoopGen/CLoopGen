#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef short int16;

extern uint32 n;
extern double *v;
extern int i;
extern int16 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (traverse arrays from end to start)
    for (i = (int)n - 1; i >= 0; i--)
        bp[i] = (int16)v[i];
}
