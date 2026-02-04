#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern gsl_histogram *h;
extern size_t i;
extern  size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    size_t *indices = (size_t*)malloc(n * sizeof(size_t));
    if (!indices) return;
    for (i = 0; i < n; i++) {
        indices[i] = i; // Populate index array
    }
    for (i = 0; i < n; i++) {
        h->bin[indices[i]] = 0;
    }
    free(indices);
}
