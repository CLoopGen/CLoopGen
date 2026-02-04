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
    // Flatten potential nesting by removing any inner loops (if present) and ensure single-level loop
    // In this case, original is already flat, so we simulate a "deeper to shallower" simplification
    // No additional nesting — pure linear traversal
    for (i = 0; i < h->n; i++)
        if (h->bin[i] > max) {
            max = h->bin[i];
            imax = i;
        }
}
