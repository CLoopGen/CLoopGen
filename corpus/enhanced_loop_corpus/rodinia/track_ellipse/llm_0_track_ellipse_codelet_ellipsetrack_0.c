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
int j;
for (j = 0; j < Np; j++) {
    t[j] = increment * (double)j;
}
}
