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
    int is_axis = (idim == axis);
    op_axes_arrays[0][idim] = is_axis ? axis : idim;
    op_axes_arrays[1][idim] = is_axis ? -1 : idim;
    op_axes_arrays[2][idim] = is_axis ? 0 : -1;
}
}
