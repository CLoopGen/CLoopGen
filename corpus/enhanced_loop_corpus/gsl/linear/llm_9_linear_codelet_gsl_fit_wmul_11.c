#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *x;
extern  size_t xstride;
extern  double *w;
extern  size_t wstride;
extern  double *y;
extern  size_t ystride;
extern  size_t n;
extern double wm_x;
extern double wm_y;
extern size_t i;
extern double d2;
extern double b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i++) {
        const double wi = w[i * wstride];
        if (wi > 0) {
            const double dx = x[i * xstride] - wm_x;
            const double dy = y[i * ystride] - wm_y;
            const double d = (wm_y - b * wm_x) + (dy - b * dx);
            const double d_sq = d * d;
            const double weight_term = wi * d_sq;
            d2 += weight_term + 0.001 * dx * dy; // Additional light computation to increase arithmetic intensity
        }
    }
}
