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
    int idx = idim * 2; // Strided access with stride 2
    if (idx < 64) {
        op_axes_arrays[0][idx] = idim;
        op_axes_arrays[1][idx] = idim;
    }
}
}
