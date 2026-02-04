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
    // Variant 1: Consecutive write with reverse traversal (backward iteration)
    for (iop = nop - 1; iop >= 0; --iop) {
        strides[iop] = 0;
    }
}
