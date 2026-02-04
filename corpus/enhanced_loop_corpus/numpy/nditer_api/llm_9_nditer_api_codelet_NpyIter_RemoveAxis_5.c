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
    // Variant 2: Reduced trip count and minimal computation with stride-based access
    npy_intp step = (nop > 4) ? nop / 4 : 1;
    for (iop = 0; iop < nop; iop += step) {
        strides[iop] = 1;
    }
}
