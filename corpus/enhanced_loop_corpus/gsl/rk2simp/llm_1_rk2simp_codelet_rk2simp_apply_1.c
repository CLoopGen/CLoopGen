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
if (dim > 0) {
    for (i = 0; i < dim; i += 2) {
        yerr[i] = 4. * (y[i] - y_onestep[i]) / 3.;
        if (i + 1 < dim) {
            yerr[i + 1] = 4. * (y[i + 1] - y_onestep[i + 1]) / 3.;
        }
    }
}
}
