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
    double scale = increment * 2.0;
    for (i = 0; i < Np; i++) {
        double idx = (double)i;
        t[i] = scale * idx - increment * idx;
    }
}
