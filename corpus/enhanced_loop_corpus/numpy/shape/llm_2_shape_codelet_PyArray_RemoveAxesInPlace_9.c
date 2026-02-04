#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char npy_bool;

typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern  npy_bool *flags;
extern npy_intp *shape;
extern npy_intp *strides;
extern int idim;
extern int ndim;
extern int idim_out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using pointer arithmetic
    npy_bool *flag_ptr = flags;
    npy_intp *shape_ptr = shape;
    npy_intp *strides_ptr = strides;
    for (idim = 0; idim < ndim; ++idim) {
        if (!(*flag_ptr)) {
            shape[idim_out] = *shape_ptr;
            strides[idim_out] = *strides_ptr;
            ++idim_out;
        }
        // Increment pointers consecutively to promote better cache locality
        ++flag_ptr;
        ++shape_ptr;
        ++strides_ptr;
    }
}
