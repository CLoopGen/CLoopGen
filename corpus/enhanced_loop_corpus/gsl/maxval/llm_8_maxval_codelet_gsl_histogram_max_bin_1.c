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
    size_t step = 2;
    double local_max = max;
    size_t local_imax = imax;
    size_t limit = h->n - (h->n % 2);

    for (i = 0; i < limit; i += step) {
        if (h->bin[i] > h->bin[i + 1]) {
            if (h->bin[i] > local_max) {
                local_max = h->bin[i];
                local_imax = i;
            }
        } else {
            if (h->bin[i + 1] > local_max) {
                local_max = h->bin[i + 1];
                local_imax = i + 1;
            }
        }
    }

    for (; i < h->n; i++) {
        if (h->bin[i] > local_max) {
            local_max = h->bin[i];
            local_imax = i;
        }
    }

    max = local_max;
    imax = local_imax;
}
