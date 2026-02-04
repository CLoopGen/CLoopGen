#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double beta;
extern size_t j;
extern size_t incY;
extern size_t lenY;
extern double *Y;
extern size_t jy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_beta = beta * beta;
    size_t temp_jy = jy;
    for (j = 0; j < lenY; ++j) {
        Y[temp_jy] *= local_beta;
        temp_jy += incY;
        Y[temp_jy] += Y[temp_jy - incY]; // Introduces RAW and WAW dependency: current iteration reads previous write
    }
    jy = temp_jy; // Update global jy after loop
}
