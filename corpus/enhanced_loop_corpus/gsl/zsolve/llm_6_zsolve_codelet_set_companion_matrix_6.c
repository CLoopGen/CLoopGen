#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *a;
extern size_t nc;
extern double *m;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp;
    for (i = 0; i < nc; i++) {
        temp = -a[i] / a[nc];
        ((m)[(i) * (nc) + (nc - 1)]) = temp;
    }
}
