#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef JSAMPARRAY *JSAMPIMAGE;

typedef unsigned int JDIMENSION;

extern JSAMPARRAY input_buf;
extern JSAMPIMAGE output_buf;
extern JDIMENSION output_row;
extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern int ci;
extern int nc;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access by transposing the iteration order
    // Instead of processing one component (ci) at a time across all columns,
    // we process all components for each column consecutively, enabling better spatial locality.

    JSAMPROW outptrs[10]; // Assume maximum nc is 10; in practice, this could be dynamic
    for (ci = 0; ci < nc; ci++) {
        outptrs[ci] = output_buf[ci][output_row];
    }
    inptr = *input_buf;

    for (col = 0; col < num_cols; col++) {
        for (ci = 0; ci < nc; ci++) {
            outptrs[ci][col] = inptr[ci + col * nc]; // Stride through input with fixed offset
        }
    }
}
