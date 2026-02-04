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
    npy_intp delta_dst = 0;
    npy_intp delta_wheremask = 0;
    int exit_loop = 0;
    for (idim = 1; idim < ndim && !exit_loop; ++idim) {
        coord[idim]++;
        if (coord[idim] >= shape_it[idim]) {
            coord[idim] = 0;
            delta_dst -= (shape_it[idim] - 1) * dst_strides_it[idim];
            delta_wheremask -= (shape_it[idim] - 1) * wheremask_strides_it[idim];
        } else {
            delta_dst += dst_strides_it[idim];
            delta_wheremask += wheremask_strides_it[idim];
            exit_loop = 1;
        }
    }
    dst_data += delta_dst;
    wheremask_data += delta_wheremask;
}
