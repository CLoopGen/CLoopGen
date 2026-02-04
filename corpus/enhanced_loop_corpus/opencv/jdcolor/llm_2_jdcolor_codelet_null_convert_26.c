#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef JSAMPARRAY *JSAMPIMAGE;

typedef unsigned int JDIMENSION;

extern JSAMPIMAGE input_buf;
extern JDIMENSION input_row;
extern JSAMPARRAY output_buf;
extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern int num_components;
extern JDIMENSION num_cols;
extern int ci;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided writes (outptr += num_components), we rewrite the output in a consecutive manner
    // by transposing the output storage order. We assume output_buf now stores data in row-major format
    // where all components for a pixel are stored contiguously.

    JSAMPROW out_row = *output_buf;
    for (col = 0; col < num_cols; col++) {
        for (ci = 0; ci < num_components; ci++) {
            inptr = input_buf[ci][input_row];
            out_row[col * num_components + ci] = inptr[col];
        }
    }
}
