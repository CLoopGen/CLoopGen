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
    idx_step = (val > 0) ? idx_step : -idx_step;
    for (i = 0; i < unravel_ndim; ++i) {
        npy_intp dim = unravel_dims[idx];
        if (dim != 0) {
            npy_intp tmp = val / dim;
            coords[idx] = val % dim;
            val = tmp;
        } else {
            coords[idx] = 0;
        }
        idx += idx_step;
    }
}
