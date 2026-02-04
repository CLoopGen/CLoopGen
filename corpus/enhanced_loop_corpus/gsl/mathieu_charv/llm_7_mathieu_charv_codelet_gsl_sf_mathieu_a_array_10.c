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
    double temp_ee_curr, temp_dd_curr, temp_ee_next;
    for (ii = 1; ii < even_order - 1; ii++) {
        temp_ee_curr = ee[ii];
        temp_dd_curr = dd[ii];
        temp_ee_next = ee[ii + 1];
        zz[ii * even_order + ii - 1] = temp_ee_curr;
        zz[ii * even_order + ii] = temp_dd_curr;
        zz[ii * even_order + ii + 1] = temp_ee_next;
    }
}
