#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t dim;
extern double y[];
extern double yerr[];
extern size_t i;
extern double *y_onestep;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double factor = 4.0 / 3.0;
    double temp1, temp2;
    for (i = 0; i < dim; i++) {
        temp1 = y[i] - y_onestep[i];
        temp2 = temp1 * factor;
        yerr[i] = temp2;
    }
}
