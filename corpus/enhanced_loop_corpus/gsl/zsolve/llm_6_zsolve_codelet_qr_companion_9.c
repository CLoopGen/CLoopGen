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
    double *local_h = h;
    size_t local_nc = nc;
    size_t local_n = n;
    double local_x = x;
    for (i = 1; i <= local_n; i++) {
        size_t idx = (i - 1) * (local_nc + 1);
        double temp = local_h[idx];
        temp -= local_x;
        local_h[idx] = temp;
    }
}
