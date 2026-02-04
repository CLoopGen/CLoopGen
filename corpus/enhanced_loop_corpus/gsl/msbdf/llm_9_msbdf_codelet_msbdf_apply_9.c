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
for (i = 2; i < ord + 1; i += 2)
    for (j = 0; j < dim; j += 2) {
        if (i < ord && (j+1) < dim) {
            z[i * dim + j]     += -l[i] * z[(ord + 1) * dim + j];
            z[i * dim + j + 1] += -l[i] * z[(ord + 1) * dim + j + 1];
        }
    }
}
