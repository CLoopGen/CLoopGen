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
    npy_intp accumulated_offset = 0;
    int exit_early = 0;
    for (idim = 1; idim < ndim && !exit_early; ++idim) {
        coord[idim]++;
        if (coord[idim] >= shape_it[idim]) {
            accumulated_offset -= (shape_it[idim] - 1) * dst_strides_it[idim];
            coord[idim] = 0;
        } else {
            accumulated_offset += dst_strides_it[idim];
            exit_early = 1;
        }
    }
    dst_data += accumulated_offset;
}
