#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int pretab[];
extern int sfb;
extern FLOAT8 sf[21];
extern int ifqstep_inv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (sfb = 11; sfb < 26; sfb++) {
    sf[sfb % 21] += pretab[sfb % 21] / ifqstep_inv;
    sf[sfb % 21] *= 1.5;
    sf[sfb % 21] -= 0.1;
}
}
