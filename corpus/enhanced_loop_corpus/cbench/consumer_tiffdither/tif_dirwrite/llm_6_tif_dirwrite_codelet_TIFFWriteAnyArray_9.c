#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 n;
extern double *v;
extern int i;
extern float *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 j;
    for (j = 0; j < n; j++) {
        float temp = (float)v[j];
        bp[j] = temp;
    }
}
