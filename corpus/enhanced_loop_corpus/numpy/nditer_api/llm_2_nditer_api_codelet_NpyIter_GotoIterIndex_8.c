#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int iop;
extern int nop;
extern npy_intp *strides;
extern npy_intp delta;
extern char **ptrs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of updating pointers based on strides, assume a flat consecutive layout.
    // We collapse the strided access into a single linear increment per operation.
    npy_intp base_delta = delta;
    for (iop = 0; iop < nop; ++iop) {
        ptrs[iop] += base_delta;
    }
}
