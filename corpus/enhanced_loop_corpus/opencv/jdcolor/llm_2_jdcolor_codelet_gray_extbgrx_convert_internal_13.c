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



void loop() {
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling
    JDIMENSION col4 = num_cols & ~3;  // Round down to multiple of 4
    JSAMPROW inptr_local = inptr;
    JSAMPROW outptr_local = outptr;

    for (col = 0; col < col4; col += 4) {
        // Unroll and write 4 pixels at once using consecutive pattern
        outptr_local[0] = inptr_local[col + 0];
        outptr_local[1] = inptr_local[col + 0];
        outptr_local[2] = inptr_local[col + 0];
        outptr_local[3] = 255;

        outptr_local[4] = inptr_local[col + 1];
        outptr_local[5] = inptr_local[col + 1];
        outptr_local[6] = inptr_local[col + 1];
        outptr_local[7] = 255;

        outptr_local[8] = inptr_local[col + 2];
        outptr_local[9] = inptr_local[col + 2];
        outptr_local[10] = inptr_local[col + 2];
        outptr_local[11] = 255;

        outptr_local[12] = inptr_local[col + 3];
        outptr_local[13] = inptr_local[col + 3];
        outptr_local[14] = inptr_local[col + 3];
        outptr_local[15] = 255;

        outptr_local += 16;
    }

    // Handle remaining columns
    for (; col < num_cols; col++) {
        outptr_local[0] = inptr_local[col];
        outptr_local[1] = inptr_local[col];
        outptr_local[2] = inptr_local[col];
        outptr_local[3] = 255;
        outptr_local += 4;
    }

    outptr = outptr_local; // Update global outptr if needed
}
