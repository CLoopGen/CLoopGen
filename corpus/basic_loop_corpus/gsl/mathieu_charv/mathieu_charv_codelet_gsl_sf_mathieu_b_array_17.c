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
for (ii = 0; ii < odd_order; ii++)
    for (jj = 0; jj < odd_order; jj++) {
        if (ii == jj)
            zz[ii * odd_order + jj] = (2 * ii + 1) * (2 * ii + 1);
        else if (ii == jj + 1 || ii + 1 == jj)
            zz[ii * odd_order + jj] = qq;
    }

}
