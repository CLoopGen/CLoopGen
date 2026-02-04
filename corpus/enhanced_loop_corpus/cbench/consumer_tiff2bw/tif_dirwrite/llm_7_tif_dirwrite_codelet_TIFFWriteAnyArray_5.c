#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef unsigned short uint16;

extern uint32 n;
extern double *v;
extern int i;
extern uint16 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 stride = 2;
    for (i = 0; i < (int)n - 1; i += stride) {
        bp[i] = (uint16)v[i];
        bp[i + 1] = (uint16)v[i + 1];
    }
    if (i < (int)n) {
        bp[i] = (uint16)v[i];
    }
}
