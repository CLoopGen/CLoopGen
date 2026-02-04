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
        for (jj = 0; jj < odd_order; jj++) {
            unsigned int diag_cond = (ii == jj);
            unsigned int off_diag_cond = (ii == jj + 1) || (ii + 1 == jj);
            if (diag_cond) {
                zz[ii * odd_order + jj] = (2 * ii + 1) * (2 * ii + 1);
            } else if (off_diag_cond) {
                zz[ii * odd_order + jj] = qq;
            }
        }
    }
}
