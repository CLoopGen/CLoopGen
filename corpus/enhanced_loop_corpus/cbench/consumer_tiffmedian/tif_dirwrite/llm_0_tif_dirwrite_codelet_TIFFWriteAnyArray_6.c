#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

typedef short int16;

extern uint32 n;
extern double *v;
extern int i;
extern int16 *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 j;
    for (j = 0; j < n; j++) {
        for (i = j; i < j + 1 && i < n; i++) {
            bp[i] = (int16)v[i];
        }
    }
}
