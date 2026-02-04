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
    // Variant 1: Strided memory access with step size of 2, unrolled by factor 2
    // Access pattern modified to process elements in strides, skipping every other element
    for (idim = 0; idim < ndim - 1; idim += 2) {
        npy_int8 p1 = (idim < xdim) ? perm[idim] : perm[idim + 1];
        npy_int8 p2 = ((idim + 1) < xdim) ? perm[idim + 1] : perm[idim + 2];

        if (p1 >= 0) {
            if (p1 > axis) {
                --p1;
            }
        } else {
            if (p1 < -1 - axis) {
                ++p1;
            }
        }

        if (p2 >= 0) {
            if (p2 > axis) {
                --p2;
            }
        } else {
            if (p2 < -1 - axis) {
                ++p2;
            }
        }

        perm[idim] = p1;
        if (idim + 1 < ndim - 1) {
            perm[idim + 1] = p2;
        }
    }
}
