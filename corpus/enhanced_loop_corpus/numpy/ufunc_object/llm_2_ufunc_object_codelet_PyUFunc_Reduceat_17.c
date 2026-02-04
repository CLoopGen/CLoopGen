#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int axis;
extern int op_axes_arrays[3][64];
extern int idim;
extern int ndim;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering computation to write one array at a time
    // This improves spatial locality by accessing each row of op_axes_arrays consecutively

    for (idim = 0; idim < ndim; ++idim) {
        if (idim == axis) {
            op_axes_arrays[0][idim] = axis;
        } else {
            op_axes_arrays[0][idim] = idim;
        }
    }

    for (idim = 0; idim < ndim; ++idim) {
        if (idim == axis) {
            op_axes_arrays[1][idim] = -1;
        } else {
            op_axes_arrays[1][idim] = idim;
        }
    }

    for (idim = 0; idim < ndim; ++idim) {
        if (idim == axis) {
            op_axes_arrays[2][idim] = 0;
        } else {
            op_axes_arrays[2][idim] = -1;
        }
    }
}
