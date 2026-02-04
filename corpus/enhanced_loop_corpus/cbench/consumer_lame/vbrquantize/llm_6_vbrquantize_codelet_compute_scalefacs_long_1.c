#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int pretab[];
extern int sfb;
extern FLOAT8 sf[21];
extern int ifqstep_inv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FLOAT8 temp[10];
    for (sfb = 11; sfb < 21; sfb++) {
        temp[sfb - 11] = pretab[sfb] / ifqstep_inv;
    }
    for (sfb = 11; sfb < 21; sfb++) {
        sf[sfb] += temp[sfb - 11];
    }
}
