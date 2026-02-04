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
    uint32 j;
    for (j = 0; j < n; j++) {
        uint8 temp = (uint8)v[j];
        bp[j] = temp;
    }
}
