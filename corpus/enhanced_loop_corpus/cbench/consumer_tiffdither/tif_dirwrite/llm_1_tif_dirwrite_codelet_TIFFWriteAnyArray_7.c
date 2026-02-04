#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 n;
extern double *v;
extern int i;
extern uint32 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 0) {
        i = 0;
        for (; i < (int)n; ) {
            bp[i] = (uint32)v[i];
            i++;
        }
    }
}
