#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t n;
    double *range;
    double *bin;
} gsl_histogram;

extern  gsl_histogram *h;
extern size_t i;
extern size_t imax;
extern double max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2) with forward traversal
    size_t stride = 2;
    max = -__builtin_huge_val();
    imax = 0;
    // First pass: even indices
    for (i = 0; i < h->n; i += stride) {
        if (h->bin[i] > max) {
            max = h->bin[i];
            imax = i;
        }
    }
    // Second pass: odd indices
    for (i = 1; i < h->n; i += stride) {
        if (h->bin[i] > max) {
            max = h->bin[i];
            imax = i;
        }
    }
}
