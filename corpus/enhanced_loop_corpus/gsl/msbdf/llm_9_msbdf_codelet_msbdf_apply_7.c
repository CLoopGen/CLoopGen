#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t dim;
extern double * z;
extern double * l;
extern size_t ord;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < ord; i++) {
    double temp = l[i] * 0.5;
    for (j = 0; j < dim; j += 2) {
        z[i * dim + j] += temp * z[ord * dim + j];
        if (j + 1 < dim) {
            z[i * dim + j + 1] += temp * z[ord * dim + j + 1];
        }
    }
}
}
