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
    double temp;
    for (i = 0; i < dim; i++) {
        temp = y[i] - y_onestep[i];
        yerr[i] = factor * temp;
    }
}
