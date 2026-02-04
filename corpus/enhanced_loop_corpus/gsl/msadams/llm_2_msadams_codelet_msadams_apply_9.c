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
    // Variant 1: Consecutive memory access by reordering computation to traverse z in increasing order
    double *z_base = &z[(ord + 1) * dim]; // Base pointer for the row used in updates
    for (j = 0; j < dim; j++) {
        double temp = z_base[j]; // Load once per column to avoid repeated access
        for (i = 2; i < ord + 1; i++) {
            z[i * dim + j] -= l[i] * temp;
        }
    }
}
