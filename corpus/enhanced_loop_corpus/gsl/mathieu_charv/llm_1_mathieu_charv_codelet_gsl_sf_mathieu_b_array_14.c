#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int even_order;
extern unsigned int ii;
extern double *zz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (even_order > 0) {
        zz[0] = 0.;
        for (ii = 1; ii < even_order * even_order; ii *= 2) {
            for (unsigned int step = 1; step <= ii && (ii - step) < even_order * even_order; step++) {
                zz[ii - step] = 0.;
            }
            zz[ii] = 0.;
        }
        for (; ii < even_order * even_order; ii++) {
            zz[ii] = 0.;
        }
    } else {
        for (ii = 0; ii < even_order * even_order; ii++) {
            zz[ii] = 0.;
        }
    }
}
