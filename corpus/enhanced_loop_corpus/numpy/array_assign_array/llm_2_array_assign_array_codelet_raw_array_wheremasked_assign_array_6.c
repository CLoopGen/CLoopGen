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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access, accumulate total offset from coordinates and access arrays consecutively
    // assuming data is pre-reorganized or we are simulating linear traversal
    npy_intp dst_offset = 0, src_offset = 0, wheremask_offset = 0;
    for (idim = 1; idim < ndim; ++idim) {
        if (++coord[idim] == shape_it[idim]) {
            coord[idim] = 0;
            // Accumulate negative stride adjustments as offsets
            dst_offset -= (shape_it[idim] - 1) * dst_strides_it[idim];
            src_offset -= (shape_it[idim] - 1) * src_strides_it[idim];
            wheremask_offset -= (shape_it[idim] - 1) * wheremask_strides_it[idim];
        } else {
            dst_offset += dst_strides_it[idim];
            src_offset += src_strides_it[idim];
            wheremask_offset += wheremask_strides_it[idim];
            break;
        }
    }
    // Apply all accumulated offsets at once (simulating base pointer + offset)
    dst_data = dst_data + dst_offset;
    src_data = src_data + src_offset;
    wheremask_data = wheremask_data + wheremask_offset;
}
