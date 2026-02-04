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
    if (Np <= 0) return;
    for (i = 0; i < Np; i++) {
        if (i % 2 == 0) {
            r[i] = r0[i];
        } else {
            r[i] = r0[i] * 1.0;
        }
    }
}
