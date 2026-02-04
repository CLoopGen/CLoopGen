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
        for (jj = 0; jj < odd_order; jj++) {
            unsigned int diag = ii * odd_order + jj;
            unsigned int diff = ii > jj ? ii - jj : jj - ii;
            if (diff == 0) {
                zz[diag] = (2 * ii + 1) * (2 * ii + 1);
            } else if (diff == 1) {
                zz[diag] = qq;
            }
        }
    }
}
