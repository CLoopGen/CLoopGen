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
    // Variant 2: Consecutive memory access with index precomputation
    // Flatten the 2D indexing into a linear sweep with conditional logic based on computed indices
    // Access memory sequentially to improve spatial locality
    unsigned int idx;
    for (idx = 0; idx < odd_order * odd_order; idx++) {
        ii = idx / odd_order;
        jj = idx % odd_order;
        if (ii == jj)
            zz[idx] = (2 * ii + 1) * (2 * ii + 1);
        else if (ii == jj + 1 || ii + 1 == jj)
            zz[idx] = qq;
    }
}
