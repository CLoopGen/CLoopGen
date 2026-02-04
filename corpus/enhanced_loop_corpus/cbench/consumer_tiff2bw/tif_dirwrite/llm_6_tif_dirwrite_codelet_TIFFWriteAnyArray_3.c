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
    for (i = 0; i < (int)n; i += 2) {
        if (i + 1 < (int)n) {
            bp[i] = (uint8)v[i];
            bp[i+1] = (uint8)v[i+1];
        } else {
            bp[i] = (uint8)v[i];
        }
    }
}
