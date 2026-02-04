#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION count;
extern int instride;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2x
    // This variant assumes num_cols is even for simplicity and processes two elements per iteration
    JDIMENSION i;
    JSAMPROW local_in = inptr;
    JSAMPROW local_out = outptr;
    for (i = num_cols / 2; i > 0; i--) {
        *local_out++ = *local_in;
        local_in += instride;
        *local_out++ = *local_in;
        local_in += instride;
    }
    // Handle odd column count if necessary
    if (num_cols % 2 != 0) {
        *local_out++ = *local_in;
    }
    outptr = local_out;
    inptr = local_in;
}
