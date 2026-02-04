#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int pretab[];
extern int sfb;
extern FLOAT8 sf[21];
extern int ifqstep_inv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FLOAT8 accumulator = 0.0;
    for (sfb = 11; sfb < 21; sfb++) {
        accumulator += pretab[sfb] / ifqstep_inv;
        sf[sfb] += accumulator;
    }
}
