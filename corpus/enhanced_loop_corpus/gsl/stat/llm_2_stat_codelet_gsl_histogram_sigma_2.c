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
extern long double wvariance;
extern long double wmean;
extern long double W;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (stride of 2, unrolled with safety check)
    size_t stride = 2;
    size_t limit = n - (n % stride); // Make sure we don't go out of bounds
    for (i = 0; i < limit; i += stride) {
        for (int s = 0; s < stride; s++) {
            size_t idx = i + s;
            double xi = (h->range[idx + 1] + h->range[idx]) / 2;
            double wi = h->bin[idx];
            if (wi > 0) {
                const long double delta = (xi - wmean);
                W += wi;
                wvariance += (delta * delta - wvariance) * (wi / W);
            }
        }
    }
    // Handle remainder elements
    for (i = limit; i < n; i++) {
        double xi = (h->range[i + 1] + h->range[i]) / 2;
        double wi = h->bin[i];
        if (wi > 0) {
            const long double delta = (xi - wmean);
            W += wi;
            wvariance += (delta * delta - wvariance) * (wi / W);
        }
    }
}
