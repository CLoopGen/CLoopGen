#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int iop;
extern int nop;
extern npy_intp *strides;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — write every second element in two passes
    // First pass: even indices
    for (iop = 0; iop < nop; iop += 2) {
        strides[iop] = 0;
    }
    // Second pass: odd indices
    for (iop = 1; iop < nop; iop += 2) {
        strides[iop] = 0;
    }
}
