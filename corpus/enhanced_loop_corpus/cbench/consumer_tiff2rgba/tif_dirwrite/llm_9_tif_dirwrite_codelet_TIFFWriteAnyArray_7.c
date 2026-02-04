#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 n;
extern double *v;
extern int i;
extern uint32 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (int)n; i++) {
        double temp = v[i] * v[i] + 0.25;
        bp[i] = (uint32)(temp > 100.0 ? temp : temp * 1.1);
    }
}
