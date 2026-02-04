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
extern double W;
extern double wm_x;
extern double wm_y;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const size_t stride = (n > 16) ? n / 8 : 1;
    for (i = 0; i < n; i += stride) {
        const double xi = x[i * xstride];
        const double yi = y[i * ystride];
        const double wi = w[i * wstride];
        if (wi > 0 && i % 3 == 0) { // Reduced trip count via conditional and stride
            double temp = wi / (W + wi);
            wm_x = wm_x * (1.0 - temp) + xi * temp;
            wm_y = wm_y * (1.0 - temp) + yi * temp;
            W += wi;
        }
    }
}
