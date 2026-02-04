#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int ndim;
extern char *dst_data;
extern char *wheremask_data;
extern int idim;
extern npy_intp shape_it[64];
extern npy_intp dst_strides_it[64];
extern npy_intp wheremask_strides_it[64];
extern npy_intp coord[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant with reduced effective loop depth: unroll first two dimensions and fall back to linear update
    if (ndim > 1) {
        idim = 1;
        if (++(coord)[idim] == (shape_it)[idim]) {
            (coord)[idim] = 0;
            (dst_data) -= ((shape_it)[idim] - 1) * (dst_strides_it)[idim];
            (wheremask_data) -= ((shape_it)[idim] - 1) * (wheremask_strides_it)[idim];
        } else {
            (dst_data) += (dst_strides_it)[idim];
            (wheremask_data) += (wheremask_strides_it)[idim];
            return;
        }
        ++idim;
        if (idim < ndim) {
            if (++(coord)[idim] == (shape_it)[idim]) {
                (coord)[idim] = 0;
                (dst_data) -= ((shape_it)[idim] - 1) * (dst_strides_it)[idim];
                (wheremask_data) -= ((shape_it)[idim] - 1) * (wheremask_strides_it)[idim];
            } else {
                (dst_data) += (dst_strides_it)[idim];
                (wheremask_data) += (wheremask_strides_it)[idim];
                return;
            }
        }
    }
}
