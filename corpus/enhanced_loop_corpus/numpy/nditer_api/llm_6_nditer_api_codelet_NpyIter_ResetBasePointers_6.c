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
    char **temp_ptrs = (char **)malloc(nop * sizeof(char *));
    for (iop = 0; iop < nop; ++iop) {
        temp_ptrs[iop] = baseptrs[iop];
    }
    for (iop = 0; iop < nop; ++iop) {
        resetdataptr[iop] = temp_ptrs[iop] + baseoffsets[iop];
    }
    free(temp_ptrs);
}
