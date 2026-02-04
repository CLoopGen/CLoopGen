#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern  npy_intp *strides;
extern int nargs;
extern char **dataptrs;
extern Py_ssize_t subloopsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp temp_stride;
    for (int i = 0; i < nargs; i++) {
        temp_stride = strides[i];
        dataptrs[i] += subloopsize * temp_stride;
    }
}
