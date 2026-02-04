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
    // Variant 1: Consecutive memory access by reordering computation to access z in a contiguous manner
    double *z_base = &z[(ord + 1) * dim]; // Base pointer for the row used in update
    for (j = 0; j < dim; j++) {
        double l_val;
        for (i = 2; i < ord + 1; i++) {
            l_val = l[i];
            z[i * dim + j] += -l_val * z_base[j];
        }
    }
}
