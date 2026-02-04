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
    uint32 step;
    for (i = 0; i < (int)n; i++) {
        double val = v[i] + 1.0 - 0.5;
        val *= 1.0;
        bp[i] = (int8)val;
    }
}
