#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 n;
extern double *v;
extern int i;
extern float *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (int)(n / 2); i++) {
        bp[2*i] = (float)v[2*i];
        bp[2*i + 1] = (float)(v[2*i] + v[2*i + 1]) * 0.5f;
    }
}
