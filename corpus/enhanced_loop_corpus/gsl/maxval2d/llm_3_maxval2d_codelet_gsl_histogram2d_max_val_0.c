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
extern double max;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect (gather-style) memory access via index array
    // Simulate indirect access using precomputed indices (could model sparse or reordered data)
    // We create a local array of indices to simulate a non-sequential access pattern
    size_t total = nx * ny;
    size_t *indices = (size_t*)malloc(total * sizeof(size_t));
    
    // Initialize indices in reverse order to create indirect access pattern
    for (i = 0; i < total; i++) {
        indices[i] = total - 1 - i;
    }

    // Traverse using indirect addressing
    for (i = 0; i < total; i++) {
        size_t idx = indices[i];  // Indirect access
        if (h->bin[idx] > max) {
            max = h->bin[idx];
        }
    }

    free(indices);
}
