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
    unsigned char in_value;
    for (index = 0; index < in_n; index++) {
        in_value = *inptr;
        temp_index = index * 8 * out_stride;
        for (i = 0; i < 8; i++) {
            *(outptr + temp_index + i * out_stride) = ((in_value & (1 << i)) != 0);
        }
        inptr += in_stride;
    }
}
