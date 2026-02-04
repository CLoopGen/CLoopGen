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
        npy_intp limit = (i + step <= in_tail) ? (i + step) : in_tail;
        npy_intp k = i;
        do {
            *outptr = ((*inptr & (1 << k)) != 0);
            outptr += out_stride;
        } while (++k < limit);
    }
}
