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
    for (i = 1; i < (int)n; i++) {
        bp[i-1] = (int16)v[i]; // Introduces WAW and WAR dependency; loop-carried dependence via index shift
    }
    if (n > 0) {
        bp[n-1] = (int16)v[0]; // Close the dependency chain; creates cyclic-like data flow across iterations
    }
}
