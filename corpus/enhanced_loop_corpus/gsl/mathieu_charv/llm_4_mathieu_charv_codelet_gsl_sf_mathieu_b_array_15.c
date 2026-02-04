#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qq;
extern unsigned int even_order;
extern unsigned int ii;
extern unsigned int jj;
extern double *zz;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < even_order; ii++) {
    for (jj = 0; jj < even_order; jj++) {
        unsigned int diag = (ii == jj);
        unsigned int off_diag = (ii == jj + 1) || (ii + 1 == jj);
        if (diag) {
            zz[ii * even_order + jj] = 4 * (ii + 1) * (ii + 1);
        } else if (off_diag) {
            zz[ii * even_order + jj] = qq;
        }
    }
}
}
