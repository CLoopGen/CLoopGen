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
    // Variant 1: Consecutive memory access with pointer arithmetic
    JSAMPROW out = outptr;
    JSAMPROW in0 = inptr0;
    JSAMPROW in1 = inptr1;
    JSAMPROW in2 = inptr2;
    for (col = 0; col < num_cols; col++) {
        *out++ = *in2++;
        *out++ = *in1++;
        *out++ = *in0++;
        *out++ = 255;
    }
    outptr = out;
}
