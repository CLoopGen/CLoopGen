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
for (i = 0; i < Np; i += 2) {
    if (i + 1 < Np) {
        r_old[i] = r[i];
        r_old[i+1] = r[i+1];
    } else {
        r_old[i] = r[i];
    }
}
}
