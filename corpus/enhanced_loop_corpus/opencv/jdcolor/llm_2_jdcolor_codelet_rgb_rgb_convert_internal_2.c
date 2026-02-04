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
    // Variant 1: Consecutive memory access with pointer arithmetic (unrolled-like pattern)
    JSAMPROW out = outptr;
    for (col = 0; col < num_cols; col++) {
        *out++ = inptr0[col];
        *out++ = inptr1[col];
        *out++ = inptr2[col];
    }
    outptr = out; // Update the global outptr to reflect advancement
}
