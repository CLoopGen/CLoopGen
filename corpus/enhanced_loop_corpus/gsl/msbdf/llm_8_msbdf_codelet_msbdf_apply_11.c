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
for (i = 1; i < ord + 1; i++)
    for (j = ord; j > i - 1; j--)
        for (k = 0; k < dim; k++) {
            z[(j - 1) * dim + k] += 2.0 * z[j * dim + k] + 1.0;
        }

}
