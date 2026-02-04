#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef signed char int8;

extern uint32 n;
extern double *v;
extern int i;
extern int8 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 step = 1;
    for (i = 0; i < (int)n; i += step) {
        bp[i] = (int8)(v[i] + 0.5);
    }
}
