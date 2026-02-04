#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Np;
extern double *t;
extern double increment;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < Np; i++) {
        t[i] = t[i-1] + increment;
    }
    if (Np > 0) {
        t[0] = 0.0;
    }
}
