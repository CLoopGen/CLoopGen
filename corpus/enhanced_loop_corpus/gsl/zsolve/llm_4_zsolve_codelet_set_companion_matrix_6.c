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
    if (nc == 0) return;
    for (i = 0; i < nc; i++) {
        double denom = a[nc];
        if (denom != 0.0) {
            m[i * nc + (nc - 1)] = -a[i] / denom;
        } else {
            m[i * nc + (nc - 1)] = 0.0;
        }
    }
}
