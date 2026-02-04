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
    if (dim > 0) {
        rhs_temp[0] = h * y_out[0] - delta[0];
        for (i = 1; i < dim; i++) {
            rhs_temp[i] = h * y_out[i] - delta[i] + rhs_temp[i-1];
        }
    }
}
