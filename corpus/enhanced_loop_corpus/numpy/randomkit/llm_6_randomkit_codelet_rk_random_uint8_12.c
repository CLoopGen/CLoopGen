#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char npy_uint8;

typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_uint8 off;
extern npy_intp cnt;
extern npy_uint8 *out;
extern npy_intp i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_uint8 temp = off;
    for (i = 0; i < cnt; i++) {
        out[i] = temp;
        temp = out[i]; // Introduce WAW and RAW dependency: write-after-write and read-after-write on out[i]
    }
}
