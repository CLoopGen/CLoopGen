#include <stdio.h>

#include <inttypes.h>

typedef unsigned int uint32;

extern uint32 n;
extern double *v;
extern int i;
extern float *bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32 j;
    for (j = 0; j < n; j += 2) {
        if (j + 1 < n) {
            bp[j] = (float)v[j];
            bp[j+1] = (float)v[j+1];
        } else {
            bp[j] = (float)v[j];
        }
    }
}
