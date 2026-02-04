#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t dim;
extern double y[];
extern double * z;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Accesses every second element in z, still mapping to consecutive y indices
    for (i = 0; i < dim; i++) {
        y[i] = z[0 * dim + 2 * i];  // Strided access: effectively z[2*i]
    }
}
