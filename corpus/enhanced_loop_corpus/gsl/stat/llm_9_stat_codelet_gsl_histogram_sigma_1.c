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
    size_t stride = 4;
    size_t limit = (n / stride) * stride;

    for (i = 0; i < limit; i += stride) {
        double temp_x[4];
        double temp_w[4];
        char valid[4] = {0};

        for (size_t j = 0; j < stride; ++j) {
            size_t idx = i + j;
            temp_x[j] = (h->range[idx + 1] + h->range[idx]) / 2;
            temp_w[j] = h->bin[idx];
            valid[j] = (temp_w[j] > 0);
        }

        for (size_t j = 0; j < stride; ++j) {
            if (valid[j]) {
                W += temp_w[j];
                wmean += (temp_x[j] - wmean) * (temp_w[j] / W);
            }
        }
    }

    for (; i < n; i++) {
        double xi = (h->range[i + 1] + h->range[i]) / 2;
        double wi = h->bin[i];
        if (wi > 0) {
            W += wi;
            wmean += (xi - wmean) * (wi / W);
        }
    }
}
