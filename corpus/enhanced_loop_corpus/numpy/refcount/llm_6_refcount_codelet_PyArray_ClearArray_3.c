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
    npy_intp temp_stride = 0;
    for (idim = 1; idim < ndim; ++idim) {
        npy_intp prev_coord = coord[idim];
        coord[idim] = (coord[idim] + 1) % shape_it[idim];
        if (prev_coord + 1 >= shape_it[idim]) {
            temp_stride -= (shape_it[idim] - 1) * strides_it[idim];
        } else {
            temp_stride += strides_it[idim];
            break;
        }
    }
    data_it += temp_stride;
}
