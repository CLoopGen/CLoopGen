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
        unsigned int idx = ii * odd_order + ii;
        unsigned int temp = 2 * ii + 1;
        zz[idx] = temp * temp;
        for (jj = 0; jj < odd_order; jj++) {
            if (ii == jj + 1) {
                zz[ii * odd_order + jj] = qq;
            } else if (ii + 1 == jj) {
                zz[ii * odd_order + jj] = qq;
            }
        }
    }
}
