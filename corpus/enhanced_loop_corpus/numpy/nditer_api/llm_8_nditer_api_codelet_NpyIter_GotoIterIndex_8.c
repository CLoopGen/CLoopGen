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
    // Variant 1: Increased computational intensity with unrolled arithmetic and doubled effective trip count
    // Unroll by 2 to increase arithmetic operations per iteration and reduce loop overhead
    npy_intp stride_iop;
    for (iop = 0; iop + 1 < nop; iop += 2) {
        stride_iop = strides[iop];
        ptrs[iop] += delta * stride_iop;
        ptrs[iop + 1] += delta * strides[iop + 1];
    }
    // Handle remaining element if nop is odd
    if (iop < nop) {
        ptrs[iop] += delta * strides[iop];
    }
}
