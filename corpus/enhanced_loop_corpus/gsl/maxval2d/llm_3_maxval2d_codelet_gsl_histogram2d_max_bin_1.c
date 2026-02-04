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
    // Variant 2: Indirect Memory Access via Index Array
    // Precompute linear indices into an array and access h->bin indirectly
    size_t total = nx * ny;
    size_t *indices = (size_t*)malloc(total * sizeof(size_t));
    if (!indices) return;  // Handle allocation failure

    // Precompute linear indices in row-major order
    for (size_t idx = 0; idx < total; idx++) {
        indices[idx] = idx;
    }

    max = -__builtin_huge_val();
    imax = 0;
    jmax = 0;

    for (size_t idx = 0; idx < total; idx++) {
        size_t linear = indices[idx];
        size_t i_temp = linear / ny;
        size_t j_temp = linear % ny;
        double x = h->bin[linear];  // Indirect access using precomputed index
        if (x > max) {
            max = x;
            imax = i_temp;
            jmax = j_temp;
        }
    }

    free(indices);
}
