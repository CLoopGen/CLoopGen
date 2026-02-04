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
    for (int j = 0; j < (int)n; j += 2) {
        bp[j] = (uint16)v[j];
        if (j + 1 < (int)n) {
            bp[j + 1] = (uint16)v[j + 1];
        }
    }
}
