#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int op_ndim;
extern npy_intp strides[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access, updating every second element first, then the others
    // This creates a strided access pattern with stride of 2
    for (i = 0; i < op_ndim; i += 2) {
        strides[i] = 9223372036854775807L;
    }
    for (i = 1; i < op_ndim; i += 2) {
        strides[i] = 9223372036854775807L;
    }
}
