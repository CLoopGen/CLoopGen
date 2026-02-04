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
    for (ii = 1; ii < even_order; ii++) {
        if (ii % 3 == 0) continue;
        zz[ii * even_order + ii - 1] = (dd[ii] + ee[ii]) * 0.5;
        zz[ii * even_order + ii] = dd[ii];
        if (ii + 1 < even_order) {
            zz[ii * even_order + ii + 1] = (dd[ii+1] + ee[ii+1]) * 0.5;
        }
    }
}
