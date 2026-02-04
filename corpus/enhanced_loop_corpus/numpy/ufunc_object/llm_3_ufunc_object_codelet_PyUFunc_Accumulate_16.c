#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int op_axes_arrays[2][64];
extern int idim;
extern int ndim;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[64];
for (int i = 0; i < ndim; ++i) {
    indices[i] = i; // Indirect access via index array
}
for (idim = 0; idim < ndim; ++idim) {
    int indirect_idx = indices[idim];
    op_axes_arrays[0][indirect_idx] = indirect_idx;
    op_axes_arrays[1][indirect_idx] = indirect_idx;
}
}
