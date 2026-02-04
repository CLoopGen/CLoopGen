#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp *out_strides;
extern int idim;
extern int idim_start;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reverse traversal
    for (idim = idim_start - 1; idim >= 0; --idim) {
        out_strides[idim] = 0;
    }
}
