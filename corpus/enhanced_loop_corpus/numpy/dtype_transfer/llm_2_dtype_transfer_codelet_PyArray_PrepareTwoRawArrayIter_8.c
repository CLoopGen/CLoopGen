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
extern  npy_intp *stridesA;
extern  npy_intp *stridesB;
extern npy_intp *out_shape;
extern npy_intp *out_stridesA;
extern npy_intp *out_stridesB;
extern npy_stride_sort_item strideperm[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Reorder the loop to access strideperm in forward order for better cache locality,
    // assuming that shape, stridesA, and stridesB are accessed indirectly via perm.
    // This improves spatial locality in strideperm traversal.

    for (i = 0; i < ndim; ++i) {
        int iperm = strideperm[i].perm;  // Access in increasing index order (consecutive)
        out_shape[ndim - i - 1] = shape[iperm];
        out_stridesA[ndim - i - 1] = stridesA[iperm];
        out_stridesB[ndim - i - 1] = stridesB[iperm];
    }
}
