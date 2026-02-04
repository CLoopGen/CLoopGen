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
    int i1;
    for (i1 = 0; i1 < Np; i1 += 2) {
        if (i1 < Np)
            r0[i1] = r[i1];
        if (i1 + 1 < Np)
            r0[i1 + 1] = r[i1 + 1];
    }
}
