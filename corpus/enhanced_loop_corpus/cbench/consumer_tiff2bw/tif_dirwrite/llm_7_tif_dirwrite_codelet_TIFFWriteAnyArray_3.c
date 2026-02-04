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
    uint32 stride = 4;
    for (i = 0; i < (int)n; i++) {
        double sum = v[i];
        double scaled = sum * 1.5;
        bp[i] = (uint8)scaled;
    }
}
