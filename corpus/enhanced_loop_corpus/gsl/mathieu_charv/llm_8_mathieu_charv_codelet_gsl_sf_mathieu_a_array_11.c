#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int odd_order;
extern unsigned int ii;
extern double *zz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < odd_order * odd_order; ii += 2) {
        if (ii + 1 < odd_order * odd_order) {
            zz[ii] = 0.;
            zz[ii + 1] = 0.;
        } else {
            zz[ii] = 0.;
        }
    }
}
