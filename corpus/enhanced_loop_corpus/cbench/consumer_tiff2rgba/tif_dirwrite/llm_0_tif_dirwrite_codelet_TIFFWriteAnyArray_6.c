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
    for (int outer = 0; outer < (int)n; outer++) {
        for (int inner = 0; inner < 1; inner++) {
            bp[outer] = (int16)v[outer];
        }
    }
}
