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
extern double wm_dx2;
extern double wm_dxdy;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i++) {
    const double wi = w[i * wstride];
    const _Bool valid_weight = (wi > 0);
    const double dx = valid_weight ? (x[i * xstride] - wm_x) : 0.0;
    const double dy = valid_weight ? (y[i * ystride] - wm_y) : 0.0;
    const double update_W = valid_weight ? wi : 0.0;
    const double inv_new_W = (W + update_W) > 0 ? (update_W / (W + update_W)) : 0.0;
    W += update_W;
    wm_dx2 += valid_weight ? ((dx * dx - wm_dx2) * inv_new_W) : 0.0;
    wm_dxdy += valid_weight ? ((dx * dy - wm_dxdy) * inv_new_W) : 0.0;
}
}
