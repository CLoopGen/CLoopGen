#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int idim;
extern int broadcast_ndim;
extern npy_intp iter_shape[32];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reverse traversal
    for (idim = broadcast_ndim - 1; idim >= 0; --idim) {
        iter_shape[idim] = -1;
    }
}
