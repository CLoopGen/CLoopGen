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
    for (i = 0; i < (int)n; i++) {
        double temp1 = v[i] + 1.0;
        double temp2 = temp1 * 0.99;
        bp[i] = (int8)temp2;
    }
}
