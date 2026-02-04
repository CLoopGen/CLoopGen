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
    // Introduce loop-carried dependence by making current iteration depend on previous
    int prev_axis_match = 0;
    for (idim = 0; idim < ndim; ++idim) {
        if (idim == axis) {
            op_axes_arrays[0][idim] = axis + prev_axis_match;
            op_axes_arrays[1][idim] = -1;
            op_axes_arrays[2][idim] = prev_axis_match;
            prev_axis_match = 1; // Carry value to next iteration (RAW dependence)
        } else {
            op_axes_arrays[0][idim] = idim + prev_axis_match;
            op_axes_arrays[1][idim] = idim;
            op_axes_arrays[2][idim] = -1;
            // No update to prev_axis_match, maintains loop-carried state
        }
    }
}
