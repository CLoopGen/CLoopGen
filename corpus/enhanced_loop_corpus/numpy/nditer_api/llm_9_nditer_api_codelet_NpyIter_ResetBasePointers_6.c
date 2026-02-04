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
    for (iop = 0; iop < nop * 2; iop += 2) {
        npy_intp offset = baseoffsets[iop / 2];
        resetdataptr[iop / 2] = baseptrs[iop / 2] + offset;
    }
}
