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
    for ((idim) = 1; (idim) < (ndim); ++(idim)) {
        npy_intp new_coord = (coord)[idim] + 1;
        npy_intp stride_val = (strides)[idim];
        npy_intp shape_val = (shape)[idim];

        (data) += (new_coord < shape_val) ? stride_val : -((shape_val - 1) * stride_val);
        (coord)[idim] = (new_coord < shape_val) ? new_coord : 0;

        if (new_coord < shape_val) {
            break;
        }
    }
}
