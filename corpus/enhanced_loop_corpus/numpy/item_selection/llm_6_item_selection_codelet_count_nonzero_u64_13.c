#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

typedef size_t npy_uintp;

extern  char *data;
extern npy_intp bstride;
extern npy_uintp len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp temp_stride = bstride;
    for (; len > 0; --len) {
        data += temp_stride;
        temp_stride = bstride; // Re-reading bstride each iteration introduces a loop-carried WAW-like dependency via temp_stride
    }
}
