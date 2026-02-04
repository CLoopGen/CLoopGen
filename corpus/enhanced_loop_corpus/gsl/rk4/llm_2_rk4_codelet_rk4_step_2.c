#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *y;
extern  double h;
extern  size_t dim;
extern  double *_usr_y0;
extern double *ytmp;
extern double *k;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols
#define y0 _usr_y0



void loop(){
    // Variant 1: Strided memory access with stride of 2
    size_t stride = 2;
    for (i = 0; i < dim; i += stride) {
        if (i + 0 < dim) {
            y[i] += h / 3. * k[i];
            ytmp[i] = y0[i] + h * k[i];
        }
        if (i + 1 < dim) {
            y[i + 1] += h / 3. * k[i + 1];
            ytmp[i + 1] = y0[i + 1] + h * k[i + 1];
        }
    }
}
