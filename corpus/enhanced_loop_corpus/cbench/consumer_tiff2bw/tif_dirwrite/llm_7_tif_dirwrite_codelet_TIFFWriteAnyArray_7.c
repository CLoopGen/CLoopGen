#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 n;
extern double *v;
extern int i;
extern uint32 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < (int)n; i++) {
        bp[i] = (uint32)v[i-1];
    }
    if (n > 0) {
        bp[0] = (uint32)v[0];
    }
}
