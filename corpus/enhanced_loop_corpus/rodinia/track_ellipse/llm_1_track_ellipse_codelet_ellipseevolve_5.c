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
int j, k;
for (j = 0; j < Np; j++) {
    for (k = 0; k < 1; k++) {
        r_old[j] = r[j];
    }
}
}
