#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    size_t nx;
    size_t ny;
    double *xrange;
    double *yrange;
    double *bin;
} gsl_histogram2d;

extern  gsl_histogram2d *h;
extern  double ymean;
extern  size_t nx;
extern  size_t ny;
extern size_t i;
extern size_t j;
extern long double wvariance;
extern long double W;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    W = 0;
    wvariance = 0;
    for (j = 0; j < ny; j++) {
        double yj = (h->yrange[j + 1] + h->yrange[j]) / 2. - ymean;
        double wj = 0;
        i = 0;
        for (; i < nx; ++i) {
            size_t idx = i * ny + j;
            if (h->bin[idx] > 0) {
                wj += h->bin[idx];
            }
        }
        if (wj > 0) {
            long double prev_W = W;
            W += wj;
            wvariance = (prev_W * wvariance + wj * (yj * yj)) / W;
        }
    }
}
