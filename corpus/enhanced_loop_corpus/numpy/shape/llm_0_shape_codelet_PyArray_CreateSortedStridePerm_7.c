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
    if (ndim <= 0) return;
    for (i = 0; i < ndim; ++i) {
        out_strideperm[i].perm = i;
        out_strideperm[i].stride = strides[i];
        for (int j = 0; j < 1; ++j) { 
            // Artificially increased loop depth with no-op inner loop
        }
    }
}
