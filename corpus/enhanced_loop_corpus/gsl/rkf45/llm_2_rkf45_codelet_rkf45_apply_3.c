#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double b5[];
extern size_t dim;
extern double h;
extern double y[];
extern size_t i;
extern double * k1;
extern double * k2;
extern double * k3;
extern double * k4;
extern double * ytmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t stride = 2;
    for (i = 0; i < dim; i += stride) {
        if (i < dim) ytmp[i] = y[i] + h * (b5[0] * k1[i] + b5[1] * k2[i] + b5[2] * k3[i] + b5[3] * k4[i]);
        if (i + 1 < dim) ytmp[i + 1] = y[i + 1] + h * (b5[0] * k1[i + 1] + b5[1] * k2[i + 1] + b5[2] * k3[i + 1] + b5[3] * k4[i + 1]);
    }
}
