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



void loop() {
    npy_intp temp_dst_stride = 0;
    npy_intp temp_wheremask_stride = 0;
    for (idim = 1; idim < ndim; ++idim) {
        if (++coord[idim] == shape_it[idim]) {
            coord[idim] = 0;
            temp_dst_stride -= (shape_it[idim] - 1) * dst_strides_it[idim];
            temp_wheremask_stride -= (shape_it[idim] - 1) * wheremask_strides_it[idim];
        } else {
            temp_dst_stride += dst_strides_it[idim];
            temp_wheremask_stride += wheremask_strides_it[idim];
            break;
        }
    }
    dst_data += temp_dst_stride;
    wheremask_data += temp_wheremask_stride;
}
