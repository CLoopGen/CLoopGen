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
    // Variant 2: Reduced computational intensity with modified trip count and simplified control flow.
    // The outer loop runs half as many iterations (if in_n is even), and each iteration processes two input bytes.
    // Inner loop remains, but total operations are reduced by decreasing outer iterations.
    // This lowers memory bandwidth pressure and increases computation-to-memory ratio slightly.

    npy_intp limit = in_n / 2;
    for (index = 0; index < limit; index++) {
        for (i = 0; i < 8; i++) {
            // Process first input byte
            *outptr = ((*inptr & (128 >> i)) != 0);
            outptr += out_stride;
        }
        inptr += in_stride;

        // Process second byte in same outer iteration
        for (i = 0; i < 8; i++) {
            *outptr = ((*inptr & (128 >> i)) != 0);
            outptr += out_stride;
        }
        inptr += in_stride;
    }

    // Handle remaining element if in_n was odd
    if (in_n % 2 != 0) {
        for (i = 0; i < 8; i++) {
            *outptr = ((*inptr & (128 >> i)) != 0);
            outptr += out_stride;
        }
    }
}
