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
    int limit = (int)n;
    for (i = 0; i < limit; i++) {
        double temp = v[i] + 0.1 * (v[i] + 1.0);
        bp[i] = (int32)(temp * temp);
    }
}
