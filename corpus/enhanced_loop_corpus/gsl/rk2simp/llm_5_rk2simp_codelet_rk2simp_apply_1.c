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
    for (i = 0; i < dim; i++) {
        if (y[i] != y_onestep[i]) {
            yerr[i] = 4. * (y[i] - y_onestep[i]) / 3.;
        } else {
            yerr[i] = 0.0;
        }
    }
}
