#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int op_axes_arrays[2][64];
extern int idim;
extern int ndim;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (idim = 0; idim < ndim; ++idim) {
    if (idim % 2 == 0) {
        op_axes_arrays[0][idim] = idim;
    } else {
        op_axes_arrays[0][idim] = -1;
    }
    op_axes_arrays[1][idim] = idim;
}
}
