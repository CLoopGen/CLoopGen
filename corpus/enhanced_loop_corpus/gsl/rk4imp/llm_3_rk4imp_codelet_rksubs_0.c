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
    // Variant 2: Strided memory access with indirect indexing via pointer arithmetic
    // Uses a fixed stride on fY and operates through pointers to simulate strided traversal
    double * restrict y_ptr = y;
    double * restrict b_ptr = b;
    const size_t stride = dim;
    for (i = 0; i < dim; i++) {
        y_ptr[i] = 0.0;
    }
    for (j = 0; j < stage; j++) {
        double b_val = b_ptr[j];
        double * fY_j = &fY[j * stride];  // Base of j-th stage block
        for (i = 0; i < dim; i++) {
            y_ptr[i] += b_val * fY_j[i];  // Strided access through block-based linear index
        }
    }
}
