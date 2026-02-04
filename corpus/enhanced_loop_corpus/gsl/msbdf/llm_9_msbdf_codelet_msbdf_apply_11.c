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
for (i = 2; i < ord + 2; i += 2)
    for (j = ord; j > i - 2; j--)
        for (k = 0; k < dim; k += 2) {
            if (j >= 1) {
                z[(j - 1) * dim + k] += z[j * dim + k];
                if (k + 1 < dim) {
                    z[(j - 1) * dim + (k + 1)] += z[j * dim + (k + 1)];
                }
            }
        }

}
