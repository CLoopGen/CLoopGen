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
    npy_intp index;
    int i;
    // Variant 1: Consecutive memory access - flatten nested loops and write output in contiguous locations
    // Assumes out_stride == 1 for consecutive writes; input still strided per byte
    char *base_outptr = outptr;
    for (index = 0; index < in_n; index++) {
        unsigned char current_byte = *inptr;
        for (i = 0; i < 8; i++) {
            base_outptr[index * 8 + i] = ((current_byte & (1 << i)) != 0);
        }
        inptr += in_stride;
    }
    // Adjust outptr to point past the last written element
    outptr = base_outptr + in_n * 8;
}
