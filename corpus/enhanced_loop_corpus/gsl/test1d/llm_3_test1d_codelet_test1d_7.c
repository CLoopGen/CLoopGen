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
extern gsl_histogram *h1;
extern size_t i;
extern int status;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index array
    size_t indices[398];
    for (size_t j = 0; j <= 397; j++) {
        indices[j] = j;
    }
    for (size_t j = 0; j <= 397; j++) {
        i = indices[j]; // Use indirect indexing
        if (h1->range[i] != h->range[i])
            status = 1;
    }
}
