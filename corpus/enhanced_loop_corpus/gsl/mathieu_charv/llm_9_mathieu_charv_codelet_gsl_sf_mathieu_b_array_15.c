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
        zz[ii * even_order + ii] = 4 * (ii + 1) * (ii + 1);
        for (jj = ii + 1; jj < even_order; jj++) {
            if (ii + 1 == jj) {
                zz[ii * even_order + jj] = qq;
                zz[jj * even_order + ii] = qq;
            }
        }
    }
}
