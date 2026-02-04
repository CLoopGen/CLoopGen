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
    for (i = 2; i < ord + 1; i++) {
        for (size_t k = 0; k < dim; k++) {
            for (j = 0; j < 1; j++) {
                z[i * dim + k] += -l[i] * z[(ord + 1) * dim + k];
            }
        }
    }
}
