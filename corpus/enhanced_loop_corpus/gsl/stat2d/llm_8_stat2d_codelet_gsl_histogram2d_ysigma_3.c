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
    // Variant 1: Increased computational intensity by unrolling the inner loop and reducing memory accesses
    for (j = 0; j < ny; j++) {
        double yj = (h->yrange[j + 1] + h->yrange[j]) * 0.5 - ymean;
        double wj = 0;
        size_t idx_base = j;
        // Unroll inner loop by factor of 4 to reduce loop overhead and increase arithmetic density
        for (i = 0; i + 3 < nx; i += 4) {
            double wij0 = h->bin[i * ny + j];
            double wij1 = h->bin[(i + 1) * ny + j];
            double wij2 = h->bin[(i + 2) * ny + j];
            double wij3 = h->bin[(i + 3) * ny + j];
            wj += (wij0 > 0 ? wij0 : 0) + (wij1 > 0 ? wij1 : 0) +
                  (wij2 > 0 ? wij2 : 0) + (wij3 > 0 ? wij3 : 0);
        }
        // Handle remaining iterations
        for (; i < nx; i++) {
            double wij = h->bin[i * ny + j];
            if (wij > 0)
                wj += wij;
        }
        if (wj > 0) {
            W += wj;
            wvariance += (yj * yj - wvariance) * (wj / W);
        }
    }
}
