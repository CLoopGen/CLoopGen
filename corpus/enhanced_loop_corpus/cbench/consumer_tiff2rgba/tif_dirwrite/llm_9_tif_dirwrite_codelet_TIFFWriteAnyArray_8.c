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
    for (i = 0; i < (int)n; i++) {
        double temp = v[i] * 2.0 + 0.5;
        bp[i] = (int32)(temp - 1.0);
        bp[i] += (int32)(temp / 2.0) & 1;
    }
}
