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
if (even_order > 2) {
    for (ii = 1; ii < even_order - 1; ii++) {
        for (unsigned int kk = ii * even_order + ii - 1; kk <= ii * even_order + ii + 1; kk++) {
            if (kk == ii * even_order + ii - 1) {
                zz[kk] = ee[ii];
            } else if (kk == ii * even_order + ii) {
                zz[kk] = dd[ii];
            } else if (kk == ii * even_order + ii + 1) {
                zz[kk] = ee[ii + 1];
            }
        }
    }
}
}
