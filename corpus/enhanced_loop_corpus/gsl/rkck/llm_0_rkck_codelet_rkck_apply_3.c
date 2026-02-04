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
        double sum = 0.0;
        for (int coeff_idx = 0; coeff_idx < 4; coeff_idx++) {
            if (coeff_idx == 0) sum += b5[0] * k1[j];
            else if (coeff_idx == 1) sum += b5[1] * k2[j];
            else if (coeff_idx == 2) sum += b5[2] * k3[j];
            else if (coeff_idx == 3) sum += b5[3] * k4[j];
        }
        ytmp[j] = y[j] + h * sum;
    }
}
