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
int j, k;
int factor = 1;
for (j = 0; j < factor; j++) {
    for (k = 0; k < Np; k++) {
        t[k] = increment * (double)k;
    }
}
}
