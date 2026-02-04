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

extern gsl_histogram2d *h;
extern size_t i;
extern  size_t nx;
extern  size_t ny;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    // Simulating indirect access pattern by precomputing indices in reverse order
    for (size_t k = 0; k < nx * ny; k++) {
        size_t i_rev = (nx * ny - 1 - k);  // Reverse indexing as a form of indirect access pattern
        h->bin[i_rev] = 0;
    }
}
