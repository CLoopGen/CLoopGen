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
    // Variant 2: Strided memory access with fixed step skipping every other element
    // Simulate strided access pattern by doubling effective stride (skip every other element)
    // This mimics accessing data with a higher stride factor, useful in filtering or subsampling.

    for (idim = 1; idim < ndim; ++idim) {
        // Double the logical stride: simulate access every 2 elements
        npy_intp effective_dst_stride = 2 * dst_strides_it[idim];
        npy_intp effective_wheremask_stride = 2 * wheremask_strides_it[idim];

        if (++coord[idim] == shape_it[idim]) {
            coord[idim] = 0;
            // Reset pointer position: step back (n-1) effective strides
            dst_data -= (shape_it[idim] - 1) * effective_dst_stride;
            wheremask_data -= (shape_it[idim] - 1) * effective_wheremask_stride;
        } else {
            // Move forward by effective (doubled) stride
            dst_data += effective_dst_stride;
            wheremask_data += effective_wheremask_stride;
            break;
        }
    }
}
