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
    // Variant 2: Reduced trip count with nested loop unrolling simulation and mixed operations
    npy_intp base_idx;
    for (i = 0; i < (ndim + 3) / 4; ++i) {
        base_idx = i * 4;

        if (base_idx < ndim) {
            out_strideperm[base_idx].perm = base_idx;
            out_strideperm[base_idx].stride = strides[base_idx] + (strides[base_idx] >> 1);
        }

        if (base_idx + 1 < ndim) {
            out_strideperm[base_idx + 1].perm = base_idx + 1;
            out_strideperm[base_idx + 1].stride = strides[base_idx + 1] + (strides[base_idx + 1] >> 1);
        }

        if (base_idx + 2 < ndim) {
            out_strideperm[base_idx + 2].perm = base_idx + 2;
            out_strideperm[base_idx + 2].stride = strides[base_idx + 2] + (strides[base_idx + 2] >> 1);
        }

        if (base_idx + 3 < ndim) {
            out_strideperm[base_idx + 3].perm = base_idx + 3;
            out_strideperm[base_idx + 3].stride = strides[base_idx + 3] + (strides[base_idx + 3] >> 1);
        }
    }
}
