#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int idim;
extern int ndim;
extern npy_intp shape_it[64];
extern npy_intp strides_it[64];
extern npy_intp coord[64];
extern char *data_it;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering operations to traverse data in contiguous blocks
    // This variant assumes that the innermost dimension (idim=1) has unit stride and attempts to process consecutive elements
    // when possible, reducing pointer arithmetic overhead.

    npy_intp base_offset = 0;
    for (idim = 1; idim < ndim; ++idim) {
        if ((strides_it)[idim] == sizeof(char)) {
            // If this dimension has unit stride (contiguous), accumulate offset and skip individual updates
            base_offset += (coord)[idim];
            (coord)[idim] = 0;
        } else {
            if (++(coord)[idim] != (shape_it)[idim]) {
                (data_it) += (strides_it)[idim];
                break;
            }
            (coord)[idim] = 0;
            (data_it) -= ((shape_it)[idim] - 1) * (strides_it)[idim];
        }
    }
    // Apply accumulated base offset for unit-stride dimensions at the end
    data_it = (char*)(((uintptr_t)data_it) + base_offset);
}
