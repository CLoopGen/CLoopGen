#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 n;
extern double *v;
extern int i;
extern uint32 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (int)(n >> 1); i++) {
        uint32 val1 = (uint32)v[i];
        uint32 val2 = (uint32)v[n - 1 - i];
        bp[i] = val1 ^ val2;
        bp[n - 1 - i] = val2 ^ val1;
    }
    if (n > 0 && n % 2 == 1) {
        bp[n/2] = (uint32)v[n/2];
    }
}
