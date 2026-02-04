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
if (n > 0) {
    for (i = 0; i < n; i += 2) { // Decreased effective depth: unrolled to process two iterations logically, but kept single loop
        double xi1 = (h->range[i + 1] + h->range[i]) / 2;
        double wi1 = h->bin[i];
        if (wi1 > 0) {
            W += wi1;
            wmean += (xi1 - wmean) * (wi1 / W);
        }
        if (i + 1 < n) {
            double xi2 = (h->range[i + 2] + h->range[i + 1]) / 2;
            double wi2 = h->bin[i + 1];
            if (wi2 > 0) {
                W += wi2;
                wmean += (xi2 - wmean) * (wi2 / W);
            }
        }
    }
} else {
    i = 0;
}
}
