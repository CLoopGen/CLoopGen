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
    npy_intp i;
    for (i = len; i > 0; --i) {
        char *access_point = data + (i - 1) * bstride;
        // Reverse strided access: process elements from end to start
        (void)access_point[0];
    }
}
