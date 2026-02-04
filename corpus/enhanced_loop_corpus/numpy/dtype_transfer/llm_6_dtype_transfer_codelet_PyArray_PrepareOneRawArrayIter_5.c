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
    npy_intp temp_shape[64];
    npy_intp temp_strides[64];
    for (i = 0; i < ndim; ++i) {
        int iperm = strideperm[ndim - i - 1].perm;
        temp_shape[i] = shape[iperm];
        temp_strides[i] = strides[iperm];
    }
    for (i = 0; i < ndim; ++i) {
        out_shape[i] = temp_shape[i];
        out_strides[i] = temp_strides[i];
    }
}
