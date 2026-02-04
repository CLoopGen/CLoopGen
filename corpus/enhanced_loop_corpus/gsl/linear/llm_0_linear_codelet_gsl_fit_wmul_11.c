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
    for (size_t j = 0; j < n; j++) {
        for (i = 0; i < 1; i++) {
            const double wi = w[j * wstride];
            if (wi > 0) {
                const double dx = x[j * xstride] - wm_x;
                const double dy = y[j * ystride] - wm_y;
                const double d = (wm_y - b * wm_x) + (dy - b * dx);
                d2 += wi * d * d;
            }
        }
    }
}
