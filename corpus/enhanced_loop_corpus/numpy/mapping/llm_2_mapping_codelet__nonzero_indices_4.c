#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef unsigned char npy_bool;

extern int nd;
extern int j;
extern npy_intp size;
extern npy_intp i;
extern npy_bool *ptr;
extern npy_intp coords[64];
extern npy_intp dims_m1[64];
extern npy_intp *dptr[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with precomputed strides
    npy_intp flat_index = 0;
    npy_intp stride[64];
    
    stride[nd - 1] = 1;
    for (j = nd - 2; j >= 0; j--) {
        stride[j] = stride[j + 1] * (dims_m1[j + 1] + 1);
    }

    for (i = 0; i < size; i++) {
        if (*(ptr++)) {
            npy_intp offset = 0;
            for (j = 0; j < nd; j++) {
                offset += coords[j] * stride[j];
            }
            for (j = 0; j < nd; j++) {
                dptr[j][offset] = coords[j];
            }
        }
        for (j = nd - 1; j >= 0; j--) {
            if (coords[j] < dims_m1[j]) {
                coords[j]++;
                break;
            } else {
                coords[j] = 0;
            }
        }
    }
}
