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
    // Variant 1: Increased computational intensity by unrolling the inner loop and increasing arithmetic operations.
    // The inner loop is fully unrolled, and redundant bit-checking logic with additional masking operations is introduced
    // to increase arithmetic density. Trip count remains the same but work per iteration is higher.

    for (index = 0; index < in_n; index++) {
        npy_intp base_out_offset = 0;
        unsigned char val = *inptr;

        *outptr = ((val & 128) != 0);
        outptr += out_stride; base_out_offset += out_stride;
        *outptr = ((val & 64) != 0);
        outptr += out_stride; base_out_offset += out_stride;
        *outptr = ((val & 32) != 0);
        outptr += out_stride; base_out_offset += out_stride;
        *outptr = ((val & 16) != 0);
        outptr += out_stride; base_out_offset += out_stride;
        *outptr = ((val & 8) != 0);
        outptr += out_stride; base_out_offset += out_stride;
        *outptr = ((val & 4) != 0);
        outptr += out_stride; base_out_offset += out_stride;
        *outptr = ((val & 2) != 0);
        outptr += out_stride; base_out_offset += out_stride;
        *outptr = ((val & 1) != 0);
        outptr += out_stride;

        inptr += in_stride;
    }
}
