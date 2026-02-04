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
    // Variant 1: Consecutive memory access with pointer arithmetic
    JSAMPROW local_out = outptr;
    const JSAMPROW local_in = inptr;
    for (JDIMENSION i = 0; i < num_cols; i++) {
        JSAMPLE val = local_in[i];
        *local_out++ = 255;
        *local_out++ = val;
        *local_out++ = val;
        *local_out++ = val;
    }
    outptr = local_out; // Update global outptr if needed by context
}
