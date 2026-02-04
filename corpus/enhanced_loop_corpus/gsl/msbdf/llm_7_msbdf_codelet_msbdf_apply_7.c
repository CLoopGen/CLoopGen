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
    for (j = 0; j < dim; j++) {
        double z_ord_j = z[ord * dim + j];
        for (i = 2; i < ord; i++) {
            z[i * dim + j] += l[i] * z_ord_j;
        }
    }
}
