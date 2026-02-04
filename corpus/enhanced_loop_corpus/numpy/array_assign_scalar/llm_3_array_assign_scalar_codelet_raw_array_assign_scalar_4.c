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



void loop() {
    // Variant 2: Strided Access with Reverse Dimension Order
    // Process dimensions in reverse order to change access pattern
    int reversed_dim;

    for (reversed_dim = ndim - 1; reversed_dim >= 1; --reversed_dim) {
        int dim = reversed_dim; // Map to original dimension
        if (++coord[dim] == shape_it[dim]) {
            coord[dim] = 0;
            dst_data -= (shape_it[dim] - 1) * dst_strides_it[dim];
        } else {
            dst_data += dst_strides_it[dim];
            break;
        }
    }
}
