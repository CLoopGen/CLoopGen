#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int unravel_ndim;
extern  npy_intp *unravel_dims;
extern npy_intp *coords;
extern int i;
extern int idx;
extern int idx_step;
extern npy_intp val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < unravel_ndim; ++i) {
        if (unravel_dims[idx] > 0) {
            npy_intp tmp = val / unravel_dims[idx];
            coords[idx] = val % unravel_dims[idx];
            val = tmp;
        }
        idx += idx_step;
    }
}
