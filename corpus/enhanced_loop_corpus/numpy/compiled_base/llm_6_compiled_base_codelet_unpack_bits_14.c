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
    npy_intp temp_stride = out_stride;
    char *local_outptr = outptr;
    for (index = 0; index < out_pad; index++) {
        *(local_outptr) = 0;
        local_outptr += temp_stride;
    }
    outptr = local_outptr;
}
