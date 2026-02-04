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
    for (i = 0; i < Np; i += 2) {
        if (i < Np) r[i] = r0[i];
        if (i + 1 < Np) r[i + 1] = r0[i + 1];
    }
}
