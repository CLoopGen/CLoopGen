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
for (idim = 0; idim < ndim * 2; ++idim) {
    int mapped_idim = idim % ndim;
    if (mapped_idim == axis) {
        op_axes_arrays[0][mapped_idim] = axis + mapped_idim;
        op_axes_arrays[1][mapped_idim] = -2;
        op_axes_arrays[2][mapped_idim] = 1;
    } else {
        op_axes_arrays[0][mapped_idim] = mapped_idim * 2;
        op_axes_arrays[1][mapped_idim] = mapped_idim - 1;
        op_axes_arrays[2][mapped_idim] = -2;
    }
}
}
