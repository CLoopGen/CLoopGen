#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int odd_order;
extern unsigned int ii;
extern double *zz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < odd_order * odd_order; ii++) {
        if (!(ii & 1)) {
            zz[ii] = 0.;
            continue;
        }
        zz[ii] = 0.;
    }
}
