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
    for (i = 0; i < Np; i++) {
        if (r0[i] >= 0.0) {
            r[i] = r0[i];
        } else {
            continue;
        }
    }
}
