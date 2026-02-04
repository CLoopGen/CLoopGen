#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int i;
extern npy_intp in_tail;
extern npy_intp out_stride;
extern  unsigned char *inptr;
extern char *outptr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    npy_intp unroll_factor = 4;
    npy_intp limit = in_tail - (in_tail % unroll_factor);
    for (i = 0; i < limit; i += unroll_factor) {
        *outptr = ((*inptr & (128 >> i)) != 0);
        outptr += out_stride;
        *outptr = ((*inptr & (128 >> (i + 1))) != 0);
        outptr += out_stride;
        *outptr = ((*inptr & (128 >> (i + 2))) != 0);
        outptr += out_stride;
        *outptr = ((*inptr & (128 >> (i + 3))) != 0);
        outptr += out_stride;
    }
    for (; i < in_tail; i++) {
        *outptr = ((*inptr & (128 >> i)) != 0);
        outptr += out_stride;
    }
}
