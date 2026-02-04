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



void loop() {
    // Variant 2: Strided memory access - process every 2nd column, then handle remainder
    JDIMENSION col;
    JDIMENSION stride = 2;
    JSAMPROW temp_inptr0 = inptr0;
    JSAMPROW temp_inptr1 = inptr1;
    JSAMPROW temp_inptr2 = inptr2;
    JSAMPROW temp_outptr = outptr;

    // First pass: strided access (every 2nd element)
    for (col = 0; col < num_cols; col += stride) {
        temp_outptr[3] = temp_inptr0[col];
        temp_outptr[2] = temp_inptr1[col];
        temp_outptr[1] = temp_inptr2[col];
        temp_outptr[0] = 255;
        temp_outptr += 4 * stride; // Stride in output as well to match access pattern
    }

    // Second pass: fill in the gaps (odd indices)
    temp_outptr = outptr + 4; // Offset by one pixel (4 bytes)
    for (col = 1; col < num_cols; col += stride) {
        temp_outptr[3] = inptr0[col];
        temp_outptr[2] = inptr1[col];
        temp_outptr[1] = inptr2[col];
        temp_outptr[0] = 255;
        temp_outptr += 4 * stride;
    }
}
