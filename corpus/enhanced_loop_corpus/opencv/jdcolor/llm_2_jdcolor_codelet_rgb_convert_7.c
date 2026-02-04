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
    // Variant 1: Consecutive memory access with pointer arithmetic (unrolled-like pattern)
    JSAMPROW out = outptr;
    JSAMPROW in0 = inptr0;
    JSAMPROW in1 = inptr1;
    JSAMPROW in2 = inptr2;
    JDIMENSION col_end = num_cols;
    
    for (col = 0; col < col_end; col++) {
        *out++ = *in0++;
        *out++ = *in1++;
        *out++ = *in2++;
    }
    outptr = out; // Update outptr to reflect advancement
}
