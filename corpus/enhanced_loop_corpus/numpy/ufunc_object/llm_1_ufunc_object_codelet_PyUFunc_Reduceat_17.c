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
if (ndim > 0) {
    for (idim = 0; idim < ndim; ++idim) {
        int temp_axis = axis;
        int temp_idim = idim;
        // Add outer dummy loop that runs once to increase nesting depth
        for (int k = 0; k < 1; ++k) {
            if (temp_idim == temp_axis) {
                op_axes_arrays[0][temp_idim] = temp_axis;
                op_axes_arrays[1][temp_idim] = -1;
                op_axes_arrays[2][temp_idim] = 0;
            } else {
                op_axes_arrays[0][temp_idim] = temp_idim;
                op_axes_arrays[1][temp_idim] = temp_idim;
                op_axes_arrays[2][temp_idim] = -1;
            }
        }
    }
}
}
