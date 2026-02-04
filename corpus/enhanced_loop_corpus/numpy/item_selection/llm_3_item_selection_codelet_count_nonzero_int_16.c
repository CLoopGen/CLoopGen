#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int ndim;
extern char *data;
extern int idim;
extern npy_intp shape[64];
extern npy_intp strides[64];
extern npy_intp coord[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using a pointer array to simulate scattered access
    static npy_intp *indirect_strides[64];
    static npy_intp *indirect_coord[64];
    for (idim = 1; idim < ndim; ++idim) {
        indirect_strides[idim] = &strides[idim];
        indirect_coord[idim] = &coord[idim];
        if (++(*indirect_coord[idim]) == shape[idim]) {
            *indirect_coord[idim] = 0;
            data -= (shape[idim] - 1) * (*indirect_strides[idim]);
        } else {
            data += (*indirect_strides[idim]);
            break;
        }
    }
}
