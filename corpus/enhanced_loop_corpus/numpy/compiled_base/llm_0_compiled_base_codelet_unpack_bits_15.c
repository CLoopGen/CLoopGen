#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern int i;
extern npy_intp in_n;
extern npy_intp in_stride;
extern npy_intp out_stride;
extern npy_intp _usr_index;
extern  unsigned char *inptr;
extern char *outptr;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    for (index = 0; index < in_n; index++) {
        *outptr = ((*inptr & 128) != 0);
        outptr += out_stride;
        *outptr = ((*inptr & 64) != 0);
        outptr += out_stride;
        *outptr = ((*inptr & 32) != 0);
        outptr += out_stride;
        *outptr = ((*inptr & 16) != 0);
        outptr += out_stride;
        *outptr = ((*inptr & 8) != 0);
        outptr += out_stride;
        *outptr = ((*inptr & 4) != 0);
        outptr += out_stride;
        *outptr = ((*inptr & 2) != 0);
        outptr += out_stride;
        *outptr = ((*inptr & 1) != 0);
        outptr += out_stride;
        inptr += in_stride;
    }
}
