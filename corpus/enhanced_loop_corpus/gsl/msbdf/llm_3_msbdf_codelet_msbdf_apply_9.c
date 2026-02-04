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
    // Variant 2: Strided memory access with stride equal to 'dim' to traverse column-wise effectively
    size_t idx, offset;
    double temp;
    for (i = 2; i < ord + 1; i++) {
        temp = -l[i];
        offset = i * dim; // Base offset for row i
        for (j = 0; j < dim; j++) {
            idx = offset + j; // Direct index into z[i][j]
            z[idx] += temp * z[(ord + 1) * dim + j];
        }
    }
}
