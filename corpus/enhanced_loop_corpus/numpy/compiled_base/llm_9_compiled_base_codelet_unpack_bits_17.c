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
    for (index = 0; index < in_n; index += 2) {
        unsigned char val1 = *inptr;
        unsigned char val2 = (in_stride == 1 && index + 1 < in_n) ? *(inptr + 1) : 0;
        for (i = 0; i < 8; i++) {
            *outptr = ((val1 & (1 << i)) != 0);
            outptr += out_stride;
            if (index + 1 < in_n) {
                *outptr = ((val2 & (1 << i)) != 0);
                outptr += out_stride;
            }
        }
        inptr += in_stride * ((index + 1 < in_n) ? 2 : 1);
    }
}
