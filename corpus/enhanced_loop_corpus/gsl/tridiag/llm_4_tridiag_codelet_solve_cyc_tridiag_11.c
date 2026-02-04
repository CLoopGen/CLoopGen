#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x[];
extern size_t x_stride;
extern size_t N;
extern double *delta;
extern double *gamma;
extern double *c;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = N - 3, j = 0; j <= N - 3; j++, i--) {
        if (gamma[i] != 0.0) {
            x[x_stride * i] = c[i] - gamma[i] * x[x_stride * (i + 1)] - delta[i] * x[x_stride * (N - 1)];
        } else {
            x[x_stride * i] = c[i] - delta[i] * x[x_stride * (N - 1)];
        }
    }
}
