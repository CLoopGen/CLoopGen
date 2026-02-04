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
extern JSAMPROW inptr3;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process every 2nd column first, then the odd ones
    JSAMPROW out = outptr;

    // Process even indices first (stride of 2)
    for (col = 0; col < num_cols; col += 2) {
        *out++ = inptr0[col];
        *out++ = inptr1[col];
        *out++ = inptr2[col];
        *out++ = inptr3[col];
    }

    // Process odd indices next (second pass, stride of 2 starting at 1)
    for (col = 1; col < num_cols; col += 2) {
        *out++ = inptr0[col];
        *out++ = inptr1[col];
        *out++ = inptr2[col];
        *out++ = inptr3[col];
    }

    outptr = out; // Update global output pointer
}
