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
    double *z_local = zz;
    unsigned int idx;
    for (ii = 0; ii < odd_order; ii++) {
        for (jj = 0; jj < odd_order; jj++) {
            idx = ii * odd_order + jj;
            if (ii == jj) {
                z_local[idx] = (2 * ii + 1) * (2 * ii + 1);
                if (ii > 0) {
                    // Introduce artificial WAW dependency by re-writing previous diagonal
                    z_local[(ii-1) * odd_order + (ii-1)] = z_local[(ii-1) * odd_order + (ii-1)] + 0.0;
                }
            } else if (ii == jj + 1 || ii + 1 == jj) {
                z_local[idx] = qq;
            }
        }
    }
}
