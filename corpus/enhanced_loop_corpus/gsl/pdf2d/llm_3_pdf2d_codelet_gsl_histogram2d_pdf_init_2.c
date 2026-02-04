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
extern size_t i;
extern  size_t n;
extern double mean;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via reverse order)
    // This changes the access pattern to indirect by traversing the array in reverse
    for (i = 0; i < n; i++) {
        size_t idx = n - 1 - i; // Reverse indexing as a form of indirect access
        mean += (h->bin[idx] - mean) / ((double)(idx + 1));
    }
}
