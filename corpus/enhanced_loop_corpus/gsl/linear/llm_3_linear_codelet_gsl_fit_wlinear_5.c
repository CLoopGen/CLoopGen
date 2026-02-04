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
    // Variant 2: Strided access with reversed loop order (backward traversal)
    for (i = n; i-- > 0;) {
        const size_t idx = i * xstride;
        const double wi = w[i * wstride];
        if (wi > 0) {
            const double dx = x[idx] - wm_x;
            const double dy = y[i * ystride] - wm_y;
            const double d = dy - b * dx;
            d2 += wi * d * d;
        }
    }
}
