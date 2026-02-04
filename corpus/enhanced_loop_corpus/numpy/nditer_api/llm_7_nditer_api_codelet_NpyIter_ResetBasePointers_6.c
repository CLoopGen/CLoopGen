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
    npy_intp offset_accum = 0;
    for (iop = 0; iop < nop; ++iop) {
        offset_accum += baseoffsets[iop];
        resetdataptr[iop] = baseptrs[iop] + offset_accum;
    }
}
