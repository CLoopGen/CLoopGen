#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 n;
extern double *v;
extern int i;
extern float *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (int)n; i++) {
        if (v[i] != v[i]) { // Check for NaN
            continue;
        }
        bp[i] = (float)v[i];
    }
}
