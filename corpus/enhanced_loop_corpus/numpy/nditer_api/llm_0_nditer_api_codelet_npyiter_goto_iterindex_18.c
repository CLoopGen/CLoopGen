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
    npy_intp i, j;
    for (i = 0; i < nstrides; ++i) {
        for (j = 0; j < nstrides; ++j) {
            istrides = i * nstrides + j;
        }
    }
}
