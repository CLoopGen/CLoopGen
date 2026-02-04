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
    // Variant 2: Indirect memory access via pointer arithmetic
    // Use base pointers and indirect indexing for data locality simulation
    npy_intp *shape_base = shape;
    npy_intp *strides_base = strides;
    npy_intp *out_shape_ptr = out_shape;
    npy_intp *out_strides_ptr = out_strides;

    for (i = 0; i < ndim; ++i) {
        int iperm = strideperm[ndim - i - 1].perm;
        *(out_shape_ptr + i) = *(shape_base + iperm);
        *(out_strides_ptr + i) = *(strides_base + iperm);
    }
}
