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
    npy_intp *indices = (npy_intp*)alloca(in_tail * sizeof(npy_intp));
    for (i = 0; i < in_tail; i++) {
        indices[i] = i * out_stride;
    }
    unsigned char in_val = *inptr;
    for (i = 0; i < in_tail; i++) {
        *(outptr + indices[i]) = ((in_val & (128 >> i)) != 0);
    }
}
