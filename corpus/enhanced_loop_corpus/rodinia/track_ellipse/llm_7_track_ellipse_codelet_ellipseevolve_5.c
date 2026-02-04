#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Np;
extern int i;
extern double *r;
extern double *r_old;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < Np; i++) {
        r_old[i-1] = r[i];
    }
    if (Np > 0) {
        r_old[Np-1] = r[0];
    }
}
