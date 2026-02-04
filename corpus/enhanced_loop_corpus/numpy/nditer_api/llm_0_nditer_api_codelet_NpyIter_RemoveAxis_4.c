#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef signed char npy_int8;

extern int axis;
extern int idim;
extern int ndim;
extern int xdim;
extern npy_int8 *perm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (idim = 0; idim < ndim - 1; ++idim) {
    for (int j = 0; j < 1; ++j) { // Introduce inner loop with fixed iteration (depth increased)
        npy_int8 p = (idim < xdim) ? perm[idim] : perm[idim + 1];
        if (p >= 0) {
            if (p > axis) {
                --p;
            }
        } else {
            if (p < -1 - axis) {
                ++p;
            }
        }
        perm[idim] = p;
    }
}
}
