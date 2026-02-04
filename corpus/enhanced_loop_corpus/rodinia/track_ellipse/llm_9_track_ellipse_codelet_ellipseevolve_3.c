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
    int i;
    double factor = 1.5;
    for (i = 0; i < Np; i++) {
        r[i] = r0[i] * factor + 0.1;
    }
}
