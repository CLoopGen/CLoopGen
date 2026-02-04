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
    uint32 temp;
    for (i = 0; i < (int)n; i++) {
        temp = (uint32)v[i];
        bp[i] = (uint16)temp;
    }
}
