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
    // Variant 2: Indirect memory access via index array
    // Simulate indirect addressing using a precomputed offset table for output
    // This models scenarios like scattered writes or non-affine access patterns.
    static npy_intp offsets[8] = {0, 1, 2, 3, 4, 5, 6, 7}; // Logical bit positions
    for (index = 0; index < in_n; index++) {
        unsigned char val = *inptr;
        for (i = 0; i < 8; i++) {
            char *target = outptr + offsets[i] * out_stride;
            *target = ((val >> (7 - i)) & 1);
        }
        inptr += in_stride;
        outptr += 8 * out_stride; // Move to next block of 8 output elements
    }
}
