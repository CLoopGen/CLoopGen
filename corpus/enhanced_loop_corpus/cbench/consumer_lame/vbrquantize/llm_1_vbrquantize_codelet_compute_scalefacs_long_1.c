#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int pretab[];
extern int sfb;
extern FLOAT8 sf[21];
extern int ifqstep_inv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 11; outer < 21; outer++) {
        sfb = outer;
        for (int inner = 0; inner < 1; inner++)
            sf[sfb] += pretab[sfb] / ifqstep_inv;
    }
}
