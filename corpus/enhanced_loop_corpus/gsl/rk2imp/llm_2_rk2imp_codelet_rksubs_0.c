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
    // Variant 1: Consecutive memory access via pointer arithmetic for better spatial locality
    double *y_ptr = y;
    double *fY_base = fY;
    for (i = 0; i < dim; i++) {
        y_ptr[i] = 0.0;
        const double *fY_ptr = fY_base + i;
        for (j = 0; j < stage; j++) {
            y_ptr[i] += b[j] * fY_ptr[j * dim];
        }
    }
}
