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
for (i = 1; i < ord; i += 2)
    for (j = 0; j < dim; j++) {
        z[i * dim + j] += l[i] * z[ord * dim + j];
        if (i + 1 < ord) {
            z[(i + 1) * dim + j] += l[i + 1] * z[ord * dim + j];
        }
    }
}
