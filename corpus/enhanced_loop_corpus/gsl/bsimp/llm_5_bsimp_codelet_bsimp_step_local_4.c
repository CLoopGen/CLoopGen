#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t dim;
extern double y_out[];
extern double * delta;
extern double * rhs_temp;
extern  double h;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_val;
    for (i = 0; i < dim; i++) {
        temp_val = h * y_out[i];
        if (temp_val > delta[i]) {
            rhs_temp[i] = temp_val - delta[i];
        } else {
            continue;
        }
    }
}
