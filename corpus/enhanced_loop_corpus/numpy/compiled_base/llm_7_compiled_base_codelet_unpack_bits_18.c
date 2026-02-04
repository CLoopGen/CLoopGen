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
    npy_intp j = in_tail - 1;
    for (i = 0; i < in_tail; i++, j--) {
        *outptr = ((*inptr & (1 << j)) != 0);
        outptr += out_stride;
    }
}
