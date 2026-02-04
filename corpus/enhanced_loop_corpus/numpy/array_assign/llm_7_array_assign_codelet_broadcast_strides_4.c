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
    npy_intp prev_stride = 0;
    for (idim = 0; idim < idim_start; ++idim) {
        out_strides[idim] = prev_stride;
        prev_stride += 1;
    }
}
