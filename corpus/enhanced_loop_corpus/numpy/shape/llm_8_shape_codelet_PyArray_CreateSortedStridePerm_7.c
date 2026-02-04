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
    // Variant 1: Increased computational intensity with trip count halved and additional arithmetic
    npy_intp temp_stride;
    for (i = 0; i < ndim; i += 2) {
        out_strideperm[i].perm = i;
        temp_stride = strides[i] * 3 + 2;  // Additional arithmetic to increase complexity
        out_strideperm[i].stride = temp_stride;

        if (i + 1 < ndim) {
            out_strideperm[i + 1].perm = i + 1;
            temp_stride = strides[i + 1] * 3 + 2;
            out_strideperm[i + 1].stride = temp_stride;
        }
    }
}
