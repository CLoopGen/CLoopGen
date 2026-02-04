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
    npy_intp indices[16];
    char *base_ptr = outptr - out_stride * ((out_pad > 16) ? 16 : out_pad);
    for (i = 0; i < out_pad; i += 16) {
        for (npy_intp j = 0; j < 16 && (i + j) < out_pad; j++) {
            indices[j] = (i + j) * out_stride;
        }
        for (npy_intp j = 0; j < 16 && (i + j) < out_pad; j++) {
            *(base_ptr + indices[j]) = 0;
        }
    }
}
