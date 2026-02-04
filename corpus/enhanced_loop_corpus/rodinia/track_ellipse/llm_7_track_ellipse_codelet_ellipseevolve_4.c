#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *r0;
extern int Np;
extern int i;
extern double *r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (Np > 0) {
        r0[0] = r[0];
        for (i = 1; i < Np; i++) {
            r0[i] = r[i] + (r0[i-1] - r0[i-1]); // Introduces a loop-carried WAW dependency (artificially using previous write)
        }
    }
}
