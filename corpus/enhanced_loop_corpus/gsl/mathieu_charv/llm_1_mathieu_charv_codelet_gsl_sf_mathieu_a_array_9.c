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
    for (ii = 0; ii < even_order * even_order; ii += even_order) {
        for (unsigned int jj = 0; jj < even_order && (ii + jj) < even_order * even_order; jj++) {
            zz[ii + jj] = 0.;
        }
    }
} else {
    // Handle zero size case
    for (ii = 0; ii < even_order * even_order; ii++) {
        zz[ii] = 0.;
    }
}
}
