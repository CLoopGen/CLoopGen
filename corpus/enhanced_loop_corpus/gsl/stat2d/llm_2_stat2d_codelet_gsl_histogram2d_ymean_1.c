#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t nx;
    size_t ny;
    double *xrange;
    double *yrange;
    double *bin;
} gsl_histogram2d;

extern  gsl_histogram2d *h;
extern  size_t nx;
extern  size_t ny;
extern size_t i;
extern size_t j;
extern long double wmean;
extern long double W;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access by reordering nested loops and using pointer arithmetic
    double *yrange_ptr = h->yrange;
    double *bin_ptr = h->bin;
    for (j = 0; j < ny; j++) {
        double yj = (yrange_ptr[j + 1] + yrange_ptr[j]) / 2.0;
        double wj = 0;
        size_t offset = j;
        for (i = 0; i < nx; i++) {
            double wij = bin_ptr[offset];  // Stride of 'ny' is replaced with consecutive access via precomputed index
            if (wij > 0)
                wj += wij;
            offset += ny;  // Maintain strided access in column-major order (each j fixed, step through i)
        }
        if (wj > 0) {
            W += wj;
            wmean += (yj - wmean) * (wj / W);
        }
    }
}
