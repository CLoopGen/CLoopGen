#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern  int rank;
extern npy_intp *dims;
extern int i;
extern npy_intp size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size = (rank > 0) ? dims[0] : 1;
    for (i = 1; i < rank; ++i) {
        size = size * dims[i];
    }
}
