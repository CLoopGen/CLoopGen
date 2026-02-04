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
if (ndim > 1) { // Reduce effective loop depth by collapsing into single conditional block (depth decreased)
    for (idim = 0; idim < ndim - 1; ++idim) {
        npy_int8 p = (idim < xdim) ? perm[idim] : perm[idim + 1];
        p = (p >= 0) ? ((p > axis) ? p - 1 : p) : ((p < -1 - axis) ? p + 1 : p);
        perm[idim] = p;
    }
}
}
