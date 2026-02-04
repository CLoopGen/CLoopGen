#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qq;
extern unsigned int odd_order;
extern unsigned int ii;
extern unsigned int jj;
extern double *zz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < odd_order; ii++) {
        zz[ii * odd_order + ii] = (2 * ii + 1) * (2 * ii + 1);
        if (ii + 1 < odd_order) {
            zz[ii * odd_order + (ii + 1)] = qq;
            zz[(ii + 1) * odd_order + ii] = qq;
        }
    }
}
