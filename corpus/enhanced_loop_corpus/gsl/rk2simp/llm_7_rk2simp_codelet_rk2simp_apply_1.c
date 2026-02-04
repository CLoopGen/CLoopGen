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
        yerr[0] = 4. * (y[0] - y_onestep[0]) / 3.;
        for (i = 1; i < dim; i++) {
            double diff_current = y[i] - y_onestep[i];
            double diff_prev = y[i-1] - y_onestep[i-1];
            yerr[i] = 4. * (diff_current + diff_prev) / 6.; 
        }
    }
}
