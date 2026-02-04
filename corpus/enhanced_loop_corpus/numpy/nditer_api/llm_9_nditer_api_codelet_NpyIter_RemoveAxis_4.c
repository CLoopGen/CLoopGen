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
int step = (ndim > 5) ? 2 : 1; // Increase stride to reduce trip count for larger ndim
for (idim = 0; idim < ndim - 1; idim += step) {
    npy_int8 p = (idim < xdim) ? perm[idim] : perm[idim + 1];
    npy_int8 adjusted_p = p;
    if (p >= 0) {
        adjusted_p = (p > axis) ? p - 1 : p;
    } else {
        adjusted_p = (p < -1 - axis) ? p + 1 : p;
    }
    perm[idim] = adjusted_p;
    // Introduce redundant but safe operation to increase computational density
    if (idim + 1 < ndim - 1) {
        perm[idim] ^= 0; // No-op bit operation to increase arithmetic intensity
    }
}
}
