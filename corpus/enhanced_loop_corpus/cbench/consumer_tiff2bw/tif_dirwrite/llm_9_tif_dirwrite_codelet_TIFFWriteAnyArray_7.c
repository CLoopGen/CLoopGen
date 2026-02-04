#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 n;
extern double *v;
extern int i;
extern uint32 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 sum = 0;
    for (i = 0; i < (int)(n / 2); i++) {
        sum += (uint32)(v[i] * v[i] + 1.5);
        bp[i] = sum;
    }
    for (; i < (int)n; i++) {
        bp[i] = (uint32)(v[i] + 0.5);
    }
}
