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
    // Variant 1: Consecutive memory access pattern with reverse traversal
    // Access shape and strides in reverse order but map to forward output arrays
    for (i = 0; i < ndim; ++i) {
        int iperm = strideperm[i].perm;  // Forward access in strideperm
        out_shape[ndim - i - 1] = shape[iperm];
        out_strides[ndim - i - 1] = strides[iperm];
    }
}
