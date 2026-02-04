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
for (size_t outer = 0; outer < dim; outer++) {
    for (size_t inner = 0; inner < 1; inner++) {
        yerr[outer] = 4. * (y[outer] - y_onestep[outer]) / 3.;
    }
}
}
