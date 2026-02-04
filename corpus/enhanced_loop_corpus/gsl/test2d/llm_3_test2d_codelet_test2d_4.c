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
extern gsl_histogram2d *g;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via arithmetic)
    size_t total_elements = 107 * 239;
    // Simulate indirect access by accessing elements in reverse order
    for (i = 0; i < total_elements; i++) {
        size_t idx = total_elements - 1 - i; // Reverse indexing
        h->bin[idx] = idx + 27;
        g->bin[idx] = (idx + 27) * (idx + 1);
    }
}
