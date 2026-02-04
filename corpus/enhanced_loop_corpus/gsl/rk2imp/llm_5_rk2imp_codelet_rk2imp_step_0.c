#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *y;
extern  double h;
extern  size_t dim;
extern  double *_usr_y0;
extern double *Y1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols
#define y0 _usr_y0



void loop(){
    for (i = 0; i < dim; i++) {
        if (Y1[i] != 0.0) {
            y[i] = y0[i] + h * Y1[i];
        } else {
            y[i] = y0[i];
        }
    }
}
