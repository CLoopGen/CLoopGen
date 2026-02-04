#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern npy_intp out_pad;
extern npy_intp out_stride;
extern npy_intp _usr_index;
extern char *outptr;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    npy_intp step = 2;
    for (index = 0; index < out_pad; index += step) {
        *outptr = 0;
        outptr += out_stride;
        if (index + 1 < out_pad) {
            *(outptr + out_stride) = 0;
        }
    }
}
