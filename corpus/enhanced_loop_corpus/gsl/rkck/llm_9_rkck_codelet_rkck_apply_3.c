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
    double b5_0 = b5[0], b5_1 = b5[1], b5_2 = b5[2], b5_3 = b5[3];
    double h_b5_0 = h * b5_0, h_b5_1 = h * b5_1, h_b5_2 = h * b5_2, h_b5_3 = h * b5_3;
    for (i = 0; i < dim; i++) {
        ytmp[i] = y[i] 
                  + h_b5_0 * k1[i] 
                  + h_b5_1 * k2[i] 
                  + h_b5_2 * k3[i] 
                  + h_b5_3 * k4[i];
    }
}
