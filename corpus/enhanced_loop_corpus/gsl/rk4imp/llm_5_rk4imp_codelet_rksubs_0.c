#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double y[];
extern  double fY[];
extern  double b[];
extern  size_t stage;
extern  size_t dim;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < dim; i++) {
        y[i] = 0.;
        size_t unroll_factor = (stage >= 4) ? 4 : 1;
        j = 0;
        for (; j + unroll_factor <= stage; j += unroll_factor) {
            y[i] += b[j] * fY[j * dim + i];
            y[i] += b[j + 1] * fY[(j + 1) * dim + i];
            if (unroll_factor > 2) {
                y[i] += b[j + 2] * fY[(j + 2) * dim + i];
                y[i] += b[j + 3] * fY[(j + 3) * dim + i];
            }
        }
        for (; j < stage; j++) {
            y[i] += b[j] * fY[j * dim + i];
        }
    }
}
