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
for (idim = 0; idim < ndim; ++idim) {
    npy_int8 p;
    if (idim < xdim) {
        p = perm[idim];
    } else if (idim < ndim - 1) {
        p = perm[idim + 1];
    } else {
        p = 0; // neutral value for out-of-bound case
    }
    if (p >= 0 && p > axis) {
        perm[idim] = p - 1;
    } else if (p < -1 - axis) {
        perm[idim] = p + 1;
    } else {
        perm[idim] = p;
    }
}
}
