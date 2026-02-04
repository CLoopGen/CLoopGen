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

extern gsl_histogram2d *h1;
extern gsl_histogram2d *g;
extern size_t i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate random access pattern
    size_t n = 107 * 239;
    size_t indices[n];
    // Generate indirect access pattern: reverse order access
    for (size_t j = 0; j < n; j++) {
        indices[j] = n - 1 - j;
    }
    for (size_t j = 0; j < n; j++) {
        i = indices[j];
        if (h1->bin[i] != 0.5 * g->bin[i])
            status = 1;
    }
}
