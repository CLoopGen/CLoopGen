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
    npy_uintp outer = len / 2;
    npy_uintp remainder = len % 2;
    for (; outer > 0; --outer) {
        data += bstride;
        data += bstride;
    }
    if (remainder) {
        data += bstride;
    }
}
