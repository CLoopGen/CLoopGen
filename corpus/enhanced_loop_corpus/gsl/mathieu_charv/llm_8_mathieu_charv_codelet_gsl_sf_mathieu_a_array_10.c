#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int even_order;
extern unsigned int ii;
extern double *dd;
extern double *ee;
extern double *zz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 2; ii < even_order - 2; ii += 2) {
        zz[ii * even_order + ii - 1] = ee[ii] + dd[ii-1];
        zz[ii * even_order + ii] = dd[ii] * 2.0;
        zz[ii * even_order + ii + 1] = ee[ii + 1] - dd[ii+1];
        zz[(ii+1) * even_order + ii] = ee[ii] * dd[ii];
        zz[ii * even_order + ii + 2] = ee[ii + 2];
    }
}
