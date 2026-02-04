#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int ndim;
extern char *dst_data;
extern char *src_data;
extern int idim;
extern npy_intp shape_it[64];
extern npy_intp dst_strides_it[64];
extern npy_intp src_strides_it[64];
extern npy_intp coord[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced loop nesting: flatten logic by unrolling first iteration and simplifying control flow
    if (ndim <= 1) return;

    int idim = 1;
    if (++(coord)[idim] == (shape_it)[idim]) {
        (coord)[idim] = 0;
        (dst_data) -= ((shape_it)[idim] - 1) * (dst_strides_it)[idim];
        (src_data) -= ((shape_it)[idim] - 1) * (src_strides_it)[idim];
        ++idim;
        for (; idim < ndim; ++idim) {
            if (++(coord)[idim] != (shape_it)[idim]) {
                (dst_data) += (dst_strides_it)[idim];
                (src_data) += (src_strides_it)[idim];
                break;
            }
            (coord)[idim] = 0;
            (dst_data) -= ((shape_it)[idim] - 1) * (dst_strides_it)[idim];
            (src_data) -= ((shape_it)[idim] - 1) * (src_strides_it)[idim];
        }
    } else {
        (dst_data) += (dst_strides_it)[idim];
        (src_data) += (src_strides_it)[idim];
    }
}
