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
    npy_uint8 pattern[] = {off, off + 1, off + 2, off + 3};
    npy_intp pattern_size = 4;
    npy_intp j = 0;
    for (i = 0; i < cnt; i++) {
        out[i] = pattern[j];
        j = (j + 1) % pattern_size;
    }
}
