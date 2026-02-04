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
    npy_intp size_temp = 1;
    for (i = rank - 1; i >= 0; --i)
        size_temp *= dims[i];
    size = size_temp;
}
