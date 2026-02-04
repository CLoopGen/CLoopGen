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
    double temp_d2 = d2;
    for (i = 0; i < n; i++) {
        const size_t idx_w = i * wstride;
        const size_t idx_x = i * xstride;
        const size_t idx_y = i * ystride;
        const double wi = w[idx_w];
        const double xi = x[idx_x];
        const double yi = y[idx_y];
        double dx, dy, d;
        if (wi > 0) {
            dx = xi - wm_x;
            dy = yi - wm_y;
            d = (wm_y - b * wm_x) + (dy - b * dx);
            temp_d2 = temp_d2 + wi * d * d;
        }
    }
    d2 = temp_d2;
}
