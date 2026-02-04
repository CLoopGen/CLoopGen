#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int pretab[];
extern int sfb;
extern FLOAT8 sf[21];
extern int ifqstep_inv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (sfb = 11; sfb < 16; sfb++) {
    FLOAT8 val = sf[sfb];
    int scaled_pretab = pretab[sfb] >> 1;
    FLOAT8 adjusted = val + scaled_pretab / (FLOAT8)(ifqstep_inv + 1);
    FLOAT8 squared = adjusted * adjusted;
    if (squared > 1.0) {
        break;
    }
}
}
