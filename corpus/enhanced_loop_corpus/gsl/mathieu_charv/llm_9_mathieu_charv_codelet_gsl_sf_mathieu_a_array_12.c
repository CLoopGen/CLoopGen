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
    unsigned int limit = odd_order > 1 ? odd_order - 1 : 0;
    for (ii = 0; ii <= limit; ii++) {
        unsigned int center_idx = ii * odd_order + ii;
        unsigned int val = 2 * ii + 1;
        zz[center_idx] = val * val;
        if (ii < limit) {
            unsigned int upper_idx = ii * odd_order + (ii + 1);
            unsigned int lower_idx = (ii + 1) * odd_order + ii;
            zz[upper_idx] = qq;
            zz[lower_idx] = qq;
        }
    }
}
