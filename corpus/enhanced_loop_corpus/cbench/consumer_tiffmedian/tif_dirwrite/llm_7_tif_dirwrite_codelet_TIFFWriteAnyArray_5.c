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
    uint16 prev = 0;
    for (i = 0; i < (int)n; i++) {
        uint16 curr = (uint16)v[i];
        bp[i] = curr + prev;
        prev = curr;
    }
}
