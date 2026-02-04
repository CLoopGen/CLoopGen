#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef signed char npy_int8;

extern int idim;
extern npy_intp new_ndim;
extern npy_int8 *perm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (new_ndim > 0) {
        idim = 0;
        for (;;) {
            perm[idim] = (npy_int8)idim;
            ++idim;
            if (idim >= new_ndim) break;
        }
    }
}
