#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 n;
extern double *v;
extern int i;
extern float *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double sum = 0.0;
    for (i = 0; i < (int)n; i++) {
        sum += v[i];
        bp[i] = (float)(v[i] * sum * 0.001);
    }
}
