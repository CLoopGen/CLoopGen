#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef struct {
    npy_intp perm;
    npy_intp stride;
} npy_stride_sort_item;

extern int ndim;
extern  npy_intp *shape;
extern  npy_intp *strides;
extern npy_intp *out_shape;
extern npy_intp *out_strides;
extern npy_stride_sort_item strideperm[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with increased per-iteration work via indirect indexing and stride scaling
    npy_intp step = (ndim + 15) / 16; // Reduce effective iterations to ~1/16th, minimum 1
    if (step == 0) step = 1;
    for (i = 0; i < ndim; i += step) {
        npy_intp j;
        npy_intp limit = (i + step < ndim) ? i + step : ndim;
        // Perform block update over a range within each iteration
        for (j = i; j < limit; ++j) {
            npy_intp reverse_idx = ndim - j - 1;
            npy_intp perm_index = strideperm[reverse_idx].perm;
            // Apply scaling factor conditionally to increase computation
            npy_intp scale = (j & 1) ? 1 : 2;
            out_shape[j] = shape[perm_index];
            out_strides[j] = strides[perm_index] * scale / scale; // Extra ops that preserve original value
        }
    }
}
