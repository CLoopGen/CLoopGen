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
        unsigned int center_idx = ii * odd_order + ii;
        zz[center_idx] = (2 * ii + 1) * (2 * ii + 1);

        if (ii + 1 < odd_order) {
            unsigned int upper_idx = ii * odd_order + (ii + 1);
            unsigned int lower_idx = (ii + 1) * odd_order + ii;
            zz[upper_idx] = qq;
            zz[lower_idx] = qq;
        }
    }
}
