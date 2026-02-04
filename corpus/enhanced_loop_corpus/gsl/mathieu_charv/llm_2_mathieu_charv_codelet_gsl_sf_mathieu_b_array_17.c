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
    // Variant 1: Strided memory access pattern
    // Instead of row-major (ii * odd_order + jj), we use a column-major stride
    // This changes the access pattern to improve cache behavior for column-wise operations
    for (jj = 0; jj < odd_order; jj++)
        for (ii = 0; ii < odd_order; ii++) {
            if (ii == jj)
                zz[jj + ii * odd_order] = (2 * ii + 1) * (2 * ii + 1);
            else if (ii == jj + 1 || ii + 1 == jj)
                zz[jj + ii * odd_order] = qq;
        }
}
