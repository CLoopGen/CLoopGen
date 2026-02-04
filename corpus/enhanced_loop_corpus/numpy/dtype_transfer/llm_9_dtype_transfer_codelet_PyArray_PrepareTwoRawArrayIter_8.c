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
    // Variant 2: Reduced trip count by unrolling and combining iterations, processing two elements per loop
    // Adjusts effective trip count to ceil(ndim/2), increasing per-iteration work
    int limit = (ndim + 1) / 2;  // Ceiling of ndim/2 for odd ndim support
    for (i = 0; i < limit; ++i) {
        int idx1 = ndim - i - 1;
        int iperm1 = strideperm[idx1].perm;
        out_shape[i] = shape[iperm1];
        out_stridesA[i] = stridesA[iperm1];
        out_stridesB[i] = stridesB[iperm1];

        if (i + i + 1 < ndim) {  // Ensure second index is valid (avoid self-overwrite when ndim is odd)
            int idx2 = ndim - (i + i + 1) - 1;
            int iperm2 = strideperm[idx2].perm;
            out_shape[i + i + 1] = shape[iperm2];
            out_stridesA[i + i + 1] = stridesA[iperm2];
            out_stridesB[i + i + 1] = stridesB[iperm2];
        }
    }
}
