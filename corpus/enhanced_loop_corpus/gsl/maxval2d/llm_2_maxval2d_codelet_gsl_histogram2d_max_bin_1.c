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
extern size_t imax;
extern size_t jmax;
extern size_t i;
extern size_t j;
extern double max;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing h->bin in row-major order (i * ny + j), we access it with a stride
    // by swapping the loop order to column-major traversal, creating strided access.
    max = -__builtin_huge_val();  // Ensure max starts low enough for correct comparison
    imax = 0;
    jmax = 0;
    for (j = 0; j < ny; j++) {
        for (i = 0; i < nx; i++) {
            double x = h->bin[j + i * ny];  // Strided access: step by ny instead of unit stride
            if (x > max) {
                max = x;
                imax = i;
                jmax = j;
            }
        }
    }
}
