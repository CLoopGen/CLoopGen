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
    for (i = 0; i < dim; i++) {
        double temp_k = k[i];
        y[i] = y[i] + (h / 3.0) * temp_k;
        ytmp[i] = y0[i] + h * temp_k;
        k[i] = temp_k; // WAW dependency introduced on k[i], though value is unchanged — creates artificial write-after-write
    }
}
