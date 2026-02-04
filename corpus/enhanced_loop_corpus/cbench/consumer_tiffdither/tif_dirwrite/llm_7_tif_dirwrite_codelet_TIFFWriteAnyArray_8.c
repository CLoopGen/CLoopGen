#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef int int32;

extern uint32 n;
extern double *v;
extern int i;
extern int32 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < (int)n; i++) {
        bp[i-1] = (int32)v[i]; // Introduces WAW and WAR dependency; loop-carried dependence via index shift
    }
    if (n > 0) {
        bp[n-1] = (int32)v[0]; // Close the dependency chain; creates cyclic-like data flow across iterations
    }
}
