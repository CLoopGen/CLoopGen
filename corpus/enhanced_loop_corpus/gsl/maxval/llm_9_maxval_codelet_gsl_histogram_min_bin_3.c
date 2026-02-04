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
extern size_t imin;
extern double min;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_min = min;
    size_t local_imin = imin;
    size_t unroll_factor = 4;
    size_t limit = h->n - (h->n % unroll_factor);
    for (i = 0; i < limit; i += unroll_factor) {
        if (h->bin[i] < local_min) {
            local_min = h->bin[i];
            local_imin = i;
        }
        if (h->bin[i+1] < local_min) {
            local_min = h->bin[i+1];
            local_imin = i+1;
        }
        if (h->bin[i+2] < local_min) {
            local_min = h->bin[i+2];
            local_imin = i+2;
        }
        if (h->bin[i+3] < local_min) {
            local_min = h->bin[i+3];
            local_imin = i+3;
        }
    }
    for (; i < h->n; i++) {
        if (h->bin[i] < local_min) {
            local_min = h->bin[i];
            local_imin = i;
        }
    }
    min = local_min;
    imin = local_imin;
}
