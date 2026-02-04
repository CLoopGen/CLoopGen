#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef short int16;

extern uint32 n;
extern double *v;
extern int i;
extern int16 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 step = 1;
    for (i = 0; i < (int)n; i += step) {
        double temp1 = v[i] + 0.5;
        double temp2 = temp1 * 1.0;
        bp[i] = (int16)temp2;
    }
}
