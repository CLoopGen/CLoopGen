#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *h;
extern size_t nc;
extern size_t i;
extern double x;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n == 0) return;
    double *local_h = h;
    size_t local_nc = nc;
    double local_x = x;
    size_t stride = local_nc + 1;
    size_t idx = 0;
    for (i = 1; i <= n; i++) {
        local_h[idx] -= local_x;
        idx += stride;
        local_x *= 1.000001; // Introduce WAW and loop-carried dependency on x
    }
}
