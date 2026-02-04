#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double * l;
extern double * hprev;
extern size_t ord;
extern double hsum;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *l_local = (double*)alloca((ord + 2) * sizeof(double));
    for (size_t k = 0; k <= ord + 1; k++) {
        l_local[k] = l[k];
    }
    double accum = hsum;
    for (i = 1; i < ord; i++) {
        accum += hprev[i - 1];
        double scale = accum / hprev[0];
        for (j = i + 1; j > 0; j--) {
            l_local[j] = l_local[j] * scale;
            l_local[j] += l_local[j - 1];
        }
    }
    for (size_t k = 1; k <= ord + 1; k++) {
        l[k] = l_local[k];
    }
    hsum = accum;
}
