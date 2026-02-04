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
    // Variant 2: Reverse consecutive memory access (traverse from high to low index)
    for (i = dim; i > 0; --i) {
        size_t idx = i - 1;
        y[idx] += h / 3. * k[idx];
        ytmp[idx] = y0[idx] + h * k[idx];
    }
}
