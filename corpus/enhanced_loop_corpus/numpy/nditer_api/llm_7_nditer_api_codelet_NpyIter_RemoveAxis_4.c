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
    npy_int8 prev_p = 0;
    for (idim = 0; idim < ndim - 1; ++idim) {
        npy_int8 p = (idim < xdim) ? perm[idim] : perm[idim + 1];
        // Introduce artificial loop-carried dependency via prev_p
        // Now each iteration depends on the previous one (RAW dependency)
        if (prev_p % 2 == 0) {
            if (p >= 0) {
                if (p > axis) {
                    --p;
                }
            } else {
                if (p < -1 - axis) {
                    ++p;
                }
            }
        } else {
            // Alternate behavior based on prior value — still valid transformation
            if (p < 0) {
                p = (p < -1 - axis) ? p + 1 : p;
            } else {
                p = (p > axis) ? p - 1 : p;
            }
        }
        perm[idim] = p;
        prev_p = p; // Carry value to next iteration, creating RAW dependence
    }
}
