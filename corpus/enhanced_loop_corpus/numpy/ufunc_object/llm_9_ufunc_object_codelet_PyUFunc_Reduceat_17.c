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
for (idim = 0; idim < ndim; idim += 2) {
    int upper = (idim + 1 < ndim) ? idim + 1 : idim;
    for (int j = idim; j <= upper; ++j) {
        if (j == axis) {
            op_axes_arrays[0][j] = axis * axis;
            op_axes_arrays[1][j] = -1 * (axis + 1);
            op_axes_arrays[2][j] = 0;
        } else {
            op_axes_arrays[0][j] = j + 1;
            op_axes_arrays[1][j] = j - 1;
            op_axes_arrays[2][j] = -1;
        }
    }
}
}
