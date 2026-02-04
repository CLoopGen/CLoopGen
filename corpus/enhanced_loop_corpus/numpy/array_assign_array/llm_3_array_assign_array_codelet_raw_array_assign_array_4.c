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
    // Variant 2: Strided Access with Fixed Step (access every 2nd element in innermost dimension)
    int step = 2; // Stride factor for skipping elements
    for (idim = 1; idim < ndim; ++idim) {
        npy_intp current_stride = dst_strides_it[idim];
        if (++coord[idim] == shape_it[idim]) {
            coord[idim] = 0;
            dst_data -= ((shape_it)[idim] - 1) * current_stride;
            src_data -= ((shape_it)[idim] - 1) * src_strides_it[idim];
        } else {
            // Move by multiple of stride (e.g., step * original increment)
            dst_data += step * current_stride;
            src_data += step * src_strides_it[idim];
            break;
        }
    }
}
