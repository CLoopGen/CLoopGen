#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (process two elements per iteration, unrolled-like pattern)
    JDIMENSION stride = 2;
    JSAMPROW out = outptr;
    for (col = 0; col + stride <= num_cols; col += stride) {
        // First element in the stride
        out[0] = inptr0[col];
        out[1] = inptr1[col];
        out[2] = inptr2[col];
        out[3] = 255;
        // Second element in the stride
        out[4] = inptr0[col + 1];
        out[5] = inptr1[col + 1];
        out[6] = inptr2[col + 1];
        out[7] = 255;
        out += 8;
    }
    // Handle remaining element if num_cols is odd
    if (col < num_cols) {
        out[0] = inptr0[col];
        out[1] = inptr1[col];
        out[2] = inptr2[col];
        out[3] = 255;
    }
}
