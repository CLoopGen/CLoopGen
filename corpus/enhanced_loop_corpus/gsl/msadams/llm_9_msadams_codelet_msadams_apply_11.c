#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t dim;
extern double * z;
extern size_t ord;
extern size_t i;
extern size_t j;
extern size_t k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < ord + 1; i += 2)
    for (j = ord; j > i - 1; j--)
        for (k = 0; k < dim; k++) {
            z[(j - 1) * dim + k] += z[j * dim + k];
            if (i + 1 <= ord && j > i) {
                z[(j - 1) * dim + k] += z[(j - 1) * dim + k];
            }
        }

}
