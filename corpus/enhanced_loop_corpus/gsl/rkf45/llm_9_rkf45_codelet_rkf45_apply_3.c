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
    size_t i;
    double b0 = b5[0], b1 = b5[1], b2 = b5[2], b3 = b5[3];
    double h_b0 = h * b0, h_b1 = h * b1, h_b2 = h * b2, h_b3 = h * b3;
    for (i = 0; i < dim; i++) {
        ytmp[i] = y[i] 
                  + h_b0 * k1[i] 
                  + h_b1 * k2[i] 
                  + h_b2 * k3[i] 
                  + h_b3 * k4[i];
    }
}
