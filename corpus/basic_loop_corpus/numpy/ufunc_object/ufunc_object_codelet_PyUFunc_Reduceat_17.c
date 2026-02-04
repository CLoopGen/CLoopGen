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
for (idim = 0; idim < ndim; ++idim) {
    if (idim == axis) {
        op_axes_arrays[0][idim] = axis;
        op_axes_arrays[1][idim] = -1;
        op_axes_arrays[2][idim] = 0;
    } else {
        op_axes_arrays[0][idim] = idim;
        op_axes_arrays[1][idim] = idim;
        op_axes_arrays[2][idim] = -1;
    }
}

}
