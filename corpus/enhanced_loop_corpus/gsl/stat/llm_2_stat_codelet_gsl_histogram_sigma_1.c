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
extern  size_t n;
extern size_t i;
extern long double wmean;
extern long double W;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element first, then the odd ones)
    size_t stride = 2;
    for (i = 0; i < n; i += stride) {
        double xi = (h->range[i + 1] + h->range[i]) / 2;
        double wi = h->bin[i];
        if (wi > 0) {
            W += wi;
            wmean += (xi - wmean) * (wi / W);
        }
    }
    for (i = 1; i < n; i += stride) {
        double xi = (h->range[i + 1] + h->range[i]) / 2;
        double wi = h->bin[i];
        if (wi > 0) {
            W += wi;
            wmean += (xi - wmean) * (wi / W);
        }
    }
}
