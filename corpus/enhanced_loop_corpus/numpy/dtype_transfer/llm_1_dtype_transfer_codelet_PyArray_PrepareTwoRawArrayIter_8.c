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
    for (i = 0; i < ndim; ++i) {
        int inner_iter = ndim - i - 1;
        for (int j = 0; j < 1; ++j) {  // Artificially increased loop depth
            int iperm = strideperm[inner_iter].perm;
            out_shape[i] = shape[iperm];
            out_stridesA[i] = stridesA[iperm];
            out_stridesB[i] = stridesB[iperm];
        }
    }
}
