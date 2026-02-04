#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern char **baseptrs;
extern int iop;
extern int nop;
extern char **resetdataptr;
extern npy_intp *baseoffsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling (access every 2nd element)
    npy_intp stride = 2;
    int iop_even = 0;
    int iop_odd = 1;
    for (; iop_even < nop; iop_even += 2) {
        resetdataptr[iop_even] = baseptrs[iop_even] + baseoffsets[iop_even];
        if (iop_odd < nop) {
            resetdataptr[iop_odd] = baseptrs[iop_odd] + baseoffsets[iop_odd];
            iop_odd += 2;
        }
    }
}
