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
    npy_intp temp_shape[64];
    npy_intp temp_stridesA[64];
    npy_intp temp_stridesB[64];
    for (i = 0; i < ndim; ++i) {
        int iperm = strideperm[ndim - i - 1].perm;
        temp_shape[i] = shape[iperm];
        temp_stridesA[i] = stridesA[iperm];
        temp_stridesB[i] = stridesB[iperm];
    }
    for (i = 0; i < ndim; ++i) {
        out_shape[i] = temp_shape[i];
        out_stridesA[i] = temp_stridesA[i];
        out_stridesB[i] = temp_stridesB[i];
    }
}
