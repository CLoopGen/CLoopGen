#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int pretab[];
extern int sfb;
extern FLOAT8 sf[21];
extern int ifqstep_inv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (sfb = 11; sfb < 21; sfb++) {
    float temp = sf[sfb] + pretab[sfb] / ifqstep_inv;
    if (temp > 0) {
        sfb = 21; // Force exit by modifying loop variable
    }
    // No break, control flow managed through assignment
}
}
