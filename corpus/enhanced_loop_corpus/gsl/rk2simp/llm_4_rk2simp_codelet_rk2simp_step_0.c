#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *y;
extern  double h;
extern  size_t dim;
extern  double *_usr_y0;
extern double *ytmp;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols
#define y0 _usr_y0



void loop(){
    for (i = 0; i < dim; i++) {
        if (y0[i] >= 0) {
            y[i] = y0[i] + h * ytmp[i];
        } else {
            y[i] = y0[i] - h * ytmp[i];
        }
    }
}
