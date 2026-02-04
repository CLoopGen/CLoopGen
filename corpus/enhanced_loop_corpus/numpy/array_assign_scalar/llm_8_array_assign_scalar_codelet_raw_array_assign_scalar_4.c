#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int ndim;
extern char *dst_data;
extern int idim;
extern npy_intp shape_it[64];
extern npy_intp dst_strides_it[64];
extern npy_intp coord[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (idim = 1; idim < ndim; ++idim) {
        npy_intp stride_val = dst_strides_it[idim];
        npy_intp shape_val = shape_it[idim];
        if (++coord[idim] == shape_val) {
            coord[idim] = 0;
            dst_data -= (shape_val - 1) * stride_val;
        } else {
            dst_data += stride_val;
            break;
        }
    }
}
