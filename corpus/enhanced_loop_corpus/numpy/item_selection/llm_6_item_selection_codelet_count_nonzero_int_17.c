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



void loop() {
    npy_intp temp_stride = 0;
    for (idim = 1; idim < ndim; ++idim) {
        coord[idim]++;
        if (coord[idim] == shape[idim]) {
            coord[idim] = 0;
            temp_stride += (shape[idim] - 1) * strides[idim];
        } else {
            temp_stride -= strides[idim];
            break;
        }
    }
    data -= temp_stride;
}
