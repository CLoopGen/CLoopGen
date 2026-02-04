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
        size_t idx = ii * odd_order + ii;
        zz[idx] = (2 * ii + 1) * (2 * ii + 1);
        if (ii > 0) {
            zz[idx - 1] = qq;
            zz[idx - odd_order] = qq;
        }
    }
}
