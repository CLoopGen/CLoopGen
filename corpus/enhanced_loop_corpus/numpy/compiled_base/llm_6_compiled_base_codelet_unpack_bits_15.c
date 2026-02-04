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
    npy_intp temp_index;
    for (index = 0; index < in_n; index++) {
        temp_index = index * in_stride;
        for (i = 0; i < 8; i++) {
            unsigned char mask = (unsigned char)(128 >> i);
            unsigned char in_val = *(inptr + temp_index);
            *outptr = ((in_val & mask) != 0);
            outptr += out_stride;
        }
    }
}
