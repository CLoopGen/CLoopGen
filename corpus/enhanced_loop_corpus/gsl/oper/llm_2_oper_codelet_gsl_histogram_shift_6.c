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
extern double shift;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (i = 0; i < h->n; i += 2) {
        h->bin[i] += shift;
        if (i + 1 < h->n) {
            h->bin[i + 1] += shift;
        }
    }
}
