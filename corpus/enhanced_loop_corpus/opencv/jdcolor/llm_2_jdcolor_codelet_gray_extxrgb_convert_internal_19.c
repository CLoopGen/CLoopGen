#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access using pointer arithmetic with pre-increment
    JSAMPROW local_out = outptr;
    const JSAMPROW local_in = inptr;
    for (JDIMENSION col = 0; col < num_cols; col++) {
        *local_out++ = 255;
        *local_out++ = local_in[col];
        *local_out++ = local_in[col];
        *local_out++ = local_in[col];
    }
    outptr = local_out; // Update global outptr if needed by caller
}
