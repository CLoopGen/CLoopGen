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
        if (i % 2 == 0) {
            r0[i] = r[i];
        } else {
            r0[i] = r[i] * 1.0;
        }
    }
}
