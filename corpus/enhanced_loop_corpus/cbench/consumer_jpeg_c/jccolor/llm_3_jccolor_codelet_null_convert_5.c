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
    // Variant 2: Strided access with reversed component iteration and indirect indexing
    // Components are accessed in reverse order, and array indexing uses pointer arithmetic
    // to simulate strided access patterns, potentially improving cache behavior in some contexts.

    for (ci = nc - 1; ci >= 0; ci--) {
        inptr = *input_buf + ci; // Start at component ci and stride by nc
        outptr = output_buf[ci][output_row];
        JDIMENSION step;
        for (step = 0; step < num_cols; step++) {
            outptr[step] = inptr[step * nc]; // Strided read from input: every nc-th element
        }
    }
}
