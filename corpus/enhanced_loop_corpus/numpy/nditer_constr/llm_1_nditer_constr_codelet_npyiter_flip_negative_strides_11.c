#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp istrides;
extern npy_intp nstrides;
extern npy_intp *baseoffsets;
extern char **resetdataptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (nstrides > 0) {
        istrides = 0;
        for (; istrides < nstrides; ++istrides) {
            resetdataptr[istrides] += baseoffsets[istrides];
        }
    }
}
