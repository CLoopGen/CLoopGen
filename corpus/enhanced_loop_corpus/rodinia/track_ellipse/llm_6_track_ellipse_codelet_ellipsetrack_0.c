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
    double temp = 0.0;
    for (i = 0; i < Np; i++) {
        temp = increment * (double)i;
        t[i] = temp;
    }
}
