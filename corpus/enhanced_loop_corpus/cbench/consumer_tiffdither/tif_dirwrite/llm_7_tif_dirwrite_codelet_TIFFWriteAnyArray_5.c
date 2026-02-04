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
    for (i = (int)n - 1; i >= 0; i--) {
        bp[i] = (uint16)v[i];
        if (i > 0) {
            bp[i-1] = (uint16)v[i-1]; 
        }
    }
}
