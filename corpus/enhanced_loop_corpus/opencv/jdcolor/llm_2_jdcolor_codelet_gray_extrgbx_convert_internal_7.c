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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling
    JSAMPROW out = outptr;
    const JSAMPROW in = inptr;
    JDIMENSION col;
    for (col = 0; col + 3 < num_cols; col += 4) {
        // Unroll and write 4 pixels at once using consecutive output pattern
        out[0] = in[col];
        out[1] = in[col];
        out[2] = in[col];
        out[3] = 255;
        out += 4;

        out[0] = in[col+1];
        out[1] = in[col+1];
        out[2] = in[col+1];
        out[3] = 255;
        out += 4;

        out[0] = in[col+2];
        out[1] = in[col+2];
        out[2] = in[col+2];
        out[3] = 255;
        out += 4;

        out[0] = in[col+3];
        out[1] = in[col+3];
        out[2] = in[col+3];
        out[3] = 255;
        out += 4;
    }
    // Handle remaining elements
    for (; col < num_cols; col++) {
        out[0] = out[1] = out[2] = in[col];
        out[3] = 255;
        out += 4;
    }
    outptr = out; // Update global outptr
}
