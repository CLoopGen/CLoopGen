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
    npy_intp step = 2;
    for (i = 0; i < in_tail; i += step) {
        *outptr = ((*inptr & (128 >> i)) != 0);
        outptr += out_stride;
        if (i + 1 < in_tail) {
            *(outptr + out_stride) = ((*inptr & (128 >> (i + 1))) != 0);
        }
    }
}
