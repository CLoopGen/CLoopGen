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
    for (size_t j = 0; j < dim; j++) {
        ytmp[j] = y[j] + h * (b5[0] * k1[j] + b5[1] * k2[j] + b5[2] * k3[j] + b5[3] * k4[j]);
    }
}
