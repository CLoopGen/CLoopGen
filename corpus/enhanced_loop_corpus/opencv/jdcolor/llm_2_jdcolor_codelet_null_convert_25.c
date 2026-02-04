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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 elements
    JDIMENSION col4 = num_cols & ~3; // Round down to multiple of 4
    JSAMPROW in0 = inptr0;
    JSAMPROW in1 = inptr1;
    JSAMPROW in2 = inptr2;
    JSAMPROW in3 = inptr3;
    JSAMPROW out = outptr;

    for (col = 0; col < col4; col += 4) {
        *out++ = in0[col + 0];
        *out++ = in1[col + 0];
        *out++ = in2[col + 0];
        *out++ = in3[col + 0];
        *out++ = in0[col + 1];
        *out++ = in1[col + 1];
        *out++ = in2[col + 1];
        *out++ = in3[col + 1];
        *out++ = in0[col + 2];
        *out++ = in1[col + 2];
        *out++ = in2[col + 2];
        *out++ = in3[col + 2];
        *out++ = in0[col + 3];
        *out++ = in1[col + 3];
        *out++ = in2[col + 3];
        *out++ = in3[col + 3];
    }

    // Handle remaining columns
    for (; col < num_cols; col++) {
        *out++ = in0[col];
        *out++ = in1[col];
        *out++ = in2[col];
        *out++ = in3[col];
    }

    outptr = out; // Update global output pointer
}
