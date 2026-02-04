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
extern gsl_histogram *g;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled by factor 2
    // Access pattern: 0, 2, 4, ..., 396 (even indices only)
    for (i = 0; i < 397; i += 2) {
        if (i + 0 < 397) {
            h->bin[i] = i + 27;
            g->bin[i] = (i + 27) * (i + 1);
        }
        if (i + 1 < 397) {
            h->bin[i + 1] = (i + 1) + 27;
            g->bin[i + 1] = ((i + 1) + 27) * ((i + 1) + 1);
        }
    }
}
