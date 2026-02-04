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
    npy_intp step = 2;
    for (idim = 0; idim < idim_start; idim += step) {
        if (idim + 1 < idim_start) {
            out_strides[idim] = 0;
            out_strides[idim + 1] = 0;
        } else {
            out_strides[idim] = 0;
        }
    }
}
