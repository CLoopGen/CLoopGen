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
    for (i = 0; i < (int)(n * 2); i++) {
        int idx = i / 2;
        double scaled = v[idx] * 1.5;
        bp[idx] = (int8)(scaled + 0.5);
    }
}
