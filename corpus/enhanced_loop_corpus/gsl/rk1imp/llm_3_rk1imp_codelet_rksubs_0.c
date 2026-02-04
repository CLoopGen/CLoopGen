#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double y[];
extern  double fY[];
extern  double b[];
extern  size_t stage;
extern  size_t dim;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect indexing using pointer arithmetic
    // Access fY in column-major-like fashion with fixed stride 'dim'
    double * restrict yp = y;
    const double * restrict bp = b;
    const double * restrict fYp = fY;
    for (i = 0; i < dim; i++) {
        yp[i] = 0.0;
        const double * col_ptr = fYp + i;  // Start at column i
        for (j = 0; j < stage; j++) {
            yp[i] += bp[j] * col_ptr[j * dim];  // Strided access: step by 'dim'
        }
    }
}
