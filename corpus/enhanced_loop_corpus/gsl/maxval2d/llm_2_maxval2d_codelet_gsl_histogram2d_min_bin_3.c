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
extern size_t imin;
extern size_t jmin;
extern size_t i;
extern size_t j;
extern double min;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of row-major (i * ny + j), we use a column-major access pattern (j * nx + i)
    // This changes the stride and memory traversal order, potentially affecting cache performance.
    min = h->bin[0];  // Initialize min with first element to avoid undefined behavior
    imin = 0;
    jmin = 0;
    for (j = 0; j < ny; j++) {
        for (i = 0; i < nx; i++) {
            double x = h->bin[j * nx + i];
            if (x < min) {
                min = x;
                imin = i;
                jmin = j;
            }
        }
    }
}
