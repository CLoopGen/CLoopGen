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
        double temp = -l[i];
        for (j = 0; j < dim; j++) {
            z[i * dim + j] += temp * z[(ord + 1) * dim + j];
        }
    }
}
