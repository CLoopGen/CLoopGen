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
    for (int depth = 0; depth < 2; ++depth) {
        for (iop = 0; iop < nop; ++iop) {
            ptrs[iop] += delta * strides[iop];
        }
    }
}
