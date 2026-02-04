#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW outptr;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access – process every 2nd column, then handle remainder
    JSAMPROW out = outptr;
    JDIMENSION stride = 2;
    JDIMENSION col;

    // Strided loop: process columns with a step of 2
    for (col = 0; col + stride <= num_cols; col += stride) {
        out[0] = inptr0[col];
        out[1] = inptr1[col];
        out[2] = inptr2[col];
        out[3] = inptr0[col + 1];
        out[4] = inptr1[col + 1];
        out[5] = inptr2[col + 1];
        out += 6;
    }

    // Handle remaining column if any
    if (col < num_cols) {
        out[0] = inptr0[col];
        out[1] = inptr1[col];
        out[2] = inptr2[col];
        out += 3;
    }

    outptr = out; // Update output pointer
}
