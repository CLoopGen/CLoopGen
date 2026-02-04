#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern JSAMPROW inptr;
extern JSAMPROW outptr0;
extern JSAMPROW outptr1;
extern JSAMPROW outptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 elements
    JDIMENSION col4;
    JSAMPROW inptr_local = inptr;
    JSAMPROW out0_local = outptr0;
    JSAMPROW out1_local = outptr1;
    JSAMPROW out2_local = outptr2;

    for (col = 0; col + 1 < num_cols; col += 2) {
        out0_local[0] = inptr_local[2];
        out1_local[0] = inptr_local[1];
        out2_local[0] = inptr_local[0];

        out0_local[1] = inptr_local[5];  // next RGB triplet: R of second pixel
        out1_local[1] = inptr_local[4];  // G of second pixel
        out2_local[1] = inptr_local[3];  // B of second pixel

        inptr_local += 6;
        out0_local += 2;
        out1_local += 2;
        out2_local += 2;
    }

    // Handle remaining element if num_cols is odd
    if (col < num_cols) {
        outptr0[col] = inptr_local[2];
        outptr1[col] = inptr_local[1];
        outptr2[col] = inptr_local[0];
    }
}
