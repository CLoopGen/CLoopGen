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
    double inc = increment;
    for (i = 0; i < Np; i += 2) {
        t[i] = inc * (double)i;
        if (i + 1 < Np) {
            t[i + 1] = inc * (double)(i + 1);
        }
    }
}
