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
    npy_intp temp_size = 1;
    for (i = 0; i < rank; ++i) {
        temp_size *= dims[i];
    }
    size = temp_size;
}
