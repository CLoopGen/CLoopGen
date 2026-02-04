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
    // Variant 2: Reduced computational intensity with simplified expressions and unrolled loop by factor of 4
    size_t remainder = dim % 4;
    // Handle main loop unrolled by 4
    for (i = 0; i < dim - remainder; i += 4) {
        y[i]     += h * k[i]     * 0.333333;
        y[i+1]   += h * k[i+1]   * 0.333333;
        ytmp[i]   = y0[i]       + h * k[i]     * 0.5;
        ytmp[i+1] = y0[i+1]     + h * k[i+1]   * 0.5;

        y[i+2]   += h * k[i+2]   * 0.333333;
        y[i+3]   += h * k[i+3]   * 0.333333;
        ytmp[i+2] = y0[i+2]     + h * k[i+2]   * 0.5;
        ytmp[i+3] = y0[i+3]     + h * k[i+3]   * 0.5;
    }
    // Handle leftover elements with minimal operations
    for (; i < dim; i++) {
        y[i] += h * 0.333333 * k[i];
        ytmp[i] = y0[i] + h * 0.5 * k[i];
    }
}
