#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef unsigned char uint8;

extern uint32 n;
extern double *v;
extern int i;
extern uint8 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int stride = 4;
    for (int s = 0; s < stride; s++)
        for (i = s; i < (int)n; i += stride)
            bp[i] = (uint8)v[i];
}
