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
    const size_t stride = 4;
    for (i = 0; i < n; i++) {
        double sum_xi = 0.0;
        double sum_wi = 0.0;
        size_t count = 0;
        for (size_t j = 0; j < stride && (i + j) < n; j++) {
            double xi = ((h->range[i + j + 1]) + (h->range[i + j])) / 2;
            double wi = h->bin[i + j];
            if (wi > 0) {
                sum_xi += xi;
                sum_wi += wi;
                count++;
            }
        }
        if (count > 0 && sum_wi > 0) {
            double avg_xi = sum_xi / count;
            const long double delta = (avg_xi - wmean);
            W += sum_wi;
            wvariance += (delta * delta - wvariance) * (sum_wi / W);
            i += stride - 1;
        }
    }
}
