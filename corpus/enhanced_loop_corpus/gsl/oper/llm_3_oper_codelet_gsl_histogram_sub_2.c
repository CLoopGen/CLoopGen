#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern gsl_histogram *h1;
extern  gsl_histogram *h2;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *indices = (size_t*)malloc(h1->n * sizeof(size_t));
    for (i = 0; i < h1->n; i++) {
        indices[i] = h1->n - 1 - i; // reverse access pattern
    }
    for (i = 0; i < h1->n; i++) {
        size_t idx = indices[i];
        h1->bin[idx] -= h2->bin[idx];
    }
    free(indices);
}
