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
    for (i = 0; i < nc; i++) {
        if (a[i] >= 0) {
            m[i * nc + (nc - 1)] = -a[i] / a[nc];
        } else {
            m[i * nc + (nc - 1)] = 0.0;
        }
    }
}
