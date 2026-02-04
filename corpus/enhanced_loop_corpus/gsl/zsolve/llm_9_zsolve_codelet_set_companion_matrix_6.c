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
    size_t j;
    for (i = 0; i < nc; i++) {
        double temp = -a[i] / a[nc];
        for (j = 0; j < 4; j++) {
            m[i * nc + (nc - 1 - j)] = temp;
        }
    }
}
