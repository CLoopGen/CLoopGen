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
    // Variant 1: Consecutive memory access with array indexing (unrolled by 4 elements)
    JDIMENSION col;
    for (col = 0; col + 3 < num_cols; col += 4) {
        // Process 4 pixels at a time, writing output in consecutive blocks
        outptr[0]  = 255; outptr[1]  = inptr2[col];   outptr[2]  = inptr1[col];   outptr[3]  = inptr0[col];
        outptr[4]  = 255; outptr[5]  = inptr2[col+1]; outptr[6]  = inptr1[col+1]; outptr[7]  = inptr0[col+1];
        outptr[8]  = 255; outptr[9]  = inptr2[col+2]; outptr[10] = inptr1[col+2]; outptr[11] = inptr0[col+2];
        outptr[12] = 255; outptr[13] = inptr2[col+3]; outptr[14] = inptr1[col+3]; outptr[15] = inptr0[col+3];
        outptr += 16;
    }
    // Handle remaining elements
    for (; col < num_cols; col++) {
        outptr[3] = inptr0[col];
        outptr[2] = inptr1[col];
        outptr[1] = inptr2[col];
        outptr[0] = 255;
        outptr += 4;
    }
}
