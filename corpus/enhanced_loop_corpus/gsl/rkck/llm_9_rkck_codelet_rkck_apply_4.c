#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double b6[];
extern size_t dim;
extern double h;
extern double y[];
extern size_t i;
extern double * k1;
extern double * k2;
extern double * k3;
extern double * k4;
extern double * k5;
extern double * ytmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double b0 = b6[0], b1 = b6[1], b2 = b6[2], b3 = b6[3], b4 = b6[4];
    double h_b0 = h * b0, h_b1 = h * b1, h_b2 = h * b2, h_b3 = h * b3, h_b4 = h * b4;
    for (i = 0; i < dim; i++) {
        double term1 = h_b0 * k1[i];
        double term2 = h_b1 * k2[i];
        double term3 = h_b2 * k3[i];
        double term4 = h_b3 * k4[i];
        double term5 = h_b4 * k5[i];
        ytmp[i] = y[i] + (term1 + term2 + term3 + term4 + term5);
    }
}
