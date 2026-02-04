#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int numnew;
extern npy_intp *mydim;
extern int i;
extern npy_intp tempsize;
extern npy_intp *mystrides;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp local_size = tempsize;
    for (i = numnew - 1; i >= 0; i--) {
        npy_intp dim = mydim[i];
        if (dim == 0) dim = 1;
        mystrides[i] = local_size;
        local_size *= dim;
    }
    tempsize = local_size;
}
