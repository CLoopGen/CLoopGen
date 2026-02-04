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
    // Variant 1: Consecutive memory access by reordering iteration to favor contiguous strides
    // Assumption: The smallest stride corresponds to the fastest varying dimension.
    // We reorder the dimensions based on stride size to access memory consecutively.
    
    npy_intp sorted_dims[64];
    npy_intp temp_strides[64];
    
    // Create a list of dimensions sorted by stride (ascending)
    for (int i = 0; i < ndim; ++i) {
        sorted_dims[i] = i;
        temp_strides[i] = dst_strides_it[i];
    }
    
    // Simple bubble sort to sort dimensions by stride (smallest first)
    for (int i = 0; i < ndim - 1; ++i) {
        for (int j = 0; j < ndim - i - 1; ++j) {
            if (temp_strides[j] > temp_strides[j + 1]) {
                // Swap strides
                npy_intp tmp_stride = temp_strides[j];
                temp_strides[j] = temp_strides[j + 1];
                temp_strides[j + 1] = tmp_stride;
                // Swap dims accordingly
                npy_intp tmp_dim = sorted_dims[j];
                sorted_dims[j] = sorted_dims[j + 1];
                sorted_dims[j + 1] = tmp_dim;
            }
        }
    }

    // Traverse in order of increasing stride (most contiguous first)
    for (int idx = 1; idx < ndim; ++idx) {
        idim = sorted_dims[idx];  // Use reordered dimension
        if (++coord[idim] == shape_it[idim]) {
            coord[idim] = 0;
            dst_data -= (shape_it[idim] - 1) * dst_strides_it[idim];
            wheremask_data -= (shape_it[idim] - 1) * wheremask_strides_it[idim];
        } else {
            dst_data += dst_strides_it[idim];
            wheremask_data += wheremask_strides_it[idim];
            break;
        }
    }
}
