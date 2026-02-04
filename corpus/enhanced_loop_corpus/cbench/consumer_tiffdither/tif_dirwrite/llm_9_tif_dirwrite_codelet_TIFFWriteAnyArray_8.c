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
    for (i = 0; i < (int)(n >> 1); i++) {
        bp[2*i] = (int32)(v[2*i] + v[2*i] * 0.1);
        bp[2*i+1] = (int32)(v[2*i+1] + v[2*i+1] * 0.1);
    }
}
