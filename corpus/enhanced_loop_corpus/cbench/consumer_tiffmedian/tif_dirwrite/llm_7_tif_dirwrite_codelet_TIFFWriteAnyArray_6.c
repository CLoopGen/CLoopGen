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
        bp[i] = (int16)v[i-1];
    }
    if (n > 0) {
        bp[0] = (int16)v[0];
    }
}
