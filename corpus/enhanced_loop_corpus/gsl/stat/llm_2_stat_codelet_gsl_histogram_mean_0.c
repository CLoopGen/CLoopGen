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
    // Variant 1: Strided Memory Access (access every 2nd element in a split pass, then handle remainder)
    size_t stride = 2;
    size_t limit = (n / stride) * stride;

    // First pass: strided access
    for (i = 0; i < limit; i += stride) {
        double xi = (h->range[i + 1] + h->range[i]) / 2;
        double wi = h->bin[i];
        if (wi > 0) {
            W += wi;
            wmean += (xi - wmean) * (wi / W);
        }
    }

    // Second pass: handle remaining elements (if n is odd)
    for (i = limit; i < n; i++) {
        double xi = (h->range[i + 1] + h->range[i]) / 2;
        double wi = h->bin[i];
        if (wi > 0) {
            W += wi;
            wmean += (xi - wmean) * (wi / W);
        }
    }
}
