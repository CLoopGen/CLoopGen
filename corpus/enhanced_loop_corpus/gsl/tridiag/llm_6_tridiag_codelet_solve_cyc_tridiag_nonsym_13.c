#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double abovediag[];
extern size_t a_stride;
extern double x[];
extern size_t x_stride;
extern size_t N;
extern double *alpha;
extern double *zb;
extern double *zu;
extern double *w;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = N - 2, j = 0; j <= N - 2; j++, i--) {
        double temp_w = (zu[i] - abovediag[a_stride * i] * w[i + 1]) / alpha[i];
        double temp_x = (zb[i] - abovediag[a_stride * i] * x[x_stride * (i + 1)]) / alpha[i];
        w[i] = temp_w;
        x[i * x_stride] = temp_x;
    }
}
