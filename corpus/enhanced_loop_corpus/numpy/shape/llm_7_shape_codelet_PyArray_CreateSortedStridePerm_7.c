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
extern  npy_intp *strides;
extern npy_stride_sort_item *out_strideperm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp local_perm;
    npy_intp local_stride;
    for (i = 0; i < ndim; ++i) {
        local_perm = i;
        local_stride = strides[i];
        out_strideperm[i].perm = local_perm;
        out_strideperm[i].stride = local_stride;
    }
}
