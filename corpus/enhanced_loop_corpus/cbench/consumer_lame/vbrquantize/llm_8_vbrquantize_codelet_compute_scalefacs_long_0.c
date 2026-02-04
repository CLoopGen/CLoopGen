#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int pretab[];
extern int sfb;
extern FLOAT8 sf[21];
extern int ifqstep_inv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (sfb = 11; sfb < 21; sfb += 2) {
    FLOAT8 temp1 = sf[sfb] + pretab[sfb] / ifqstep_inv;
    FLOAT8 temp2 = sf[sfb+1] + pretab[sfb+1] / ifqstep_inv;
    if (temp1 > 0 || temp2 > 0) {
        break;
    }
}
}
