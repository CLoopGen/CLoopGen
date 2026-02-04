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
    npy_intp factor = 3;
    npy_intp extended_count = idim_start * factor;
    for (idim = 0; idim < extended_count; ++idim) {
        npy_intp mapped_index = idim % idim_start;
        out_strides[mapped_index] = 0;
    }
}
