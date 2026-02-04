#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp istrides;
extern npy_intp nstrides;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp prev = 0;
    for (istrides = 0; istrides < nstrides; ++istrides) {
        npy_intp current = prev + istrides; // RAW dependency: `prev` read after write from previous iteration
        prev = current;
    }
    // Loop-carried dependence introduced via `prev`: each iteration depends on the prior
}
