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
    if (in_tail > 0) {
        i = 0;
        npy_intp temp_stride = 0;
        for (npy_intp block = 0; block < in_tail; block += 8) {
            for (i = block; i < block + 8 && i < in_tail; i++) {
                *outptr = ((*inptr & (128 >> i)) != 0);
                outptr += out_stride;
            }
        }
    }
}
