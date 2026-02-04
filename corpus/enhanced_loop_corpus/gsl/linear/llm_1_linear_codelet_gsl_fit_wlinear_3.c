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
    // Transform original loop into a doubly nested structure by splitting the iteration space
    size_t chunk_size = 16;
    size_t outer_n = (n + chunk_size - 1) / chunk_size;
    for (size_t ii = 0; ii < outer_n; ii++) {
        for (size_t jj = 0; jj < chunk_size; jj++) {
            i = ii * chunk_size + jj;
            if (i >= n) break;
            const double wi = w[i * wstride];
            if (wi > 0) {
                W += wi;
                wm_x += (x[i * xstride] - wm_x) * (wi / W);
                wm_y += (y[i * ystride] - wm_y) * (wi / W);
            }
        }
    }
}
