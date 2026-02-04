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
    for (ii = 1; ii < even_order - 1; ii++) {
        zz[ii * even_order + ii - 1] = ee[ii];
        if (ii % 2 == 0) {
            zz[ii * even_order + ii] = dd[ii];
        } else {
            zz[ii * even_order + ii] = -dd[ii];
        }
        zz[ii * even_order + ii + 1] = ee[ii + 1];
    }
}
