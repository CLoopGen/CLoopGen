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
    npy_uint8 local_off = off ^ 0xFF;
    for (i = 0; i < cnt * 3; i++) {
        out[i % cnt] ^= local_off;
    }
}
