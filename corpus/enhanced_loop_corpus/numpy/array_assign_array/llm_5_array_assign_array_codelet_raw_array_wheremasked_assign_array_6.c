#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int ndim;
extern char *dst_data;
extern char *src_data;
extern char *wheremask_data;
extern int idim;
extern npy_intp shape_it[64];
extern npy_intp dst_strides_it[64];
extern npy_intp src_strides_it[64];
extern npy_intp wheremask_strides_it[64];
extern npy_intp coord[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for ((idim) = 1; (idim) < (ndim); ++(idim)) {
        npy_intp old_coord = (coord)[idim];
        npy_intp new_coord = old_coord + 1;
        (coord)[idim] = new_coord;

        npy_intp dst_stride_val = (dst_strides_it)[idim];
        npy_intp src_stride_val = (src_strides_it)[idim];
        npy_intp where_stride_val = (wheremask_strides_it)[idim];
        npy_intp dim_shape = (shape_it)[idim];

        (dst_data) += (new_coord < dim_shape) ? dst_stride_val : -((dim_shape - 1) * dst_stride_val);
        (src_data) += (new_coord < dim_shape) ? src_stride_val : -((dim_shape - 1) * src_stride_val);
        (wheremask_data) += (new_coord < dim_shape) ? where_stride_val : -((dim_shape - 1) * where_stride_val);

        if (new_coord < dim_shape) {
            break;
        } else {
            continue;
        }
    }
}
