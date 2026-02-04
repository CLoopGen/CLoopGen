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
        // Handle diagonal element first without branching inside jj-loop
        zz[ii * odd_order + ii] = (2 * ii + 1) * (2 * ii + 1);

        // Now handle off-diagonal: only jj = ii-1 and jj = ii+1
        if (ii + 1 < odd_order) {
            zz[ii * odd_order + (ii + 1)] = qq;
        }
        if (ii > 0) {
            zz[ii * odd_order + (ii - 1)] = qq;
        }
    }
}
