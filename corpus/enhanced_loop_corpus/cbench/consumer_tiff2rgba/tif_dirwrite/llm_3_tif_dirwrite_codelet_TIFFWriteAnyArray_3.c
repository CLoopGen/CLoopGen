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
    for (i = 0; i < (int)n; i++)
        bp[i * stride % n] = (uint8)v[i * stride % n];
}
