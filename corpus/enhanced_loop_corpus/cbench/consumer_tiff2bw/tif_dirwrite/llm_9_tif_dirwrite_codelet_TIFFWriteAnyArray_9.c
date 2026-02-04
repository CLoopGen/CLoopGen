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
        double temp1 = v[i] * 1.5;
        double temp2 = temp1 + 0.3;
        bp[i] = (float)(temp2);
    }
}
