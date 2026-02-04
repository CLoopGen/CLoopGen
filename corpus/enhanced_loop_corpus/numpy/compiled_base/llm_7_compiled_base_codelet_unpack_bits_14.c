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
    npy_intp i;
    char *base_outptr = outptr;
    for (i = 0; i < out_pad; i++) {
        *(base_outptr + i * out_stride) = 0;
    }
    if (out_pad > 0) {
        outptr = base_outptr + (out_pad - 1) * out_stride + out_stride;
    }
}
