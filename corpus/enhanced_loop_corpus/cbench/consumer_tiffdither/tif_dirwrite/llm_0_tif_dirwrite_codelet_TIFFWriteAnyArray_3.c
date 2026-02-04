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
    for (int j = 0; j < (int)n; j++) {
        for (i = j; i < j + 1 && i < (int)n; i++)
            bp[i] = (uint8)v[i];
    }
}
