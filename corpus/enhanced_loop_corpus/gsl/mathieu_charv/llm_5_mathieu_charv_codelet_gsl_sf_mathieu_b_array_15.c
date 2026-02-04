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
    size_t base_idx = ii * even_order;
    double val = 4 * (ii + 1) * (ii + 1);
    for (jj = 0; jj < even_order; jj++) {
        if (ii == jj) {
            zz[base_idx + jj] = val;
        } else if (ii - 1 == jj || ii + 1 == jj) {
            zz[base_idx + jj] = qq;
        }
    }
}
}
