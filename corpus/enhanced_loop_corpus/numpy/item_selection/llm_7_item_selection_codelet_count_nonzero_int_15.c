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
    npy_intp base_offset = 0;
    int update_occurred = 0;
    for (idim = 1; idim < ndim && !update_occurred; ++idim) {
        coord[idim] = (coord[idim] + 1) % shape[idim];
        if (coord[idim] != 0) {
            base_offset = strides[idim];
            update_occurred = 1;
        } else {
            base_offset = -(shape[idim] - 1) * strides[idim];
        }
        data += base_offset;
    }
}
