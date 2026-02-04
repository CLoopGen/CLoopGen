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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 iterations
    JDIMENSION col = 0;
    JSAMPROW inptr_local = inptr;
    for (; col < num_cols - 1; col += 2) {
        outptr0[col]     = inptr_local[0];
        outptr1[col]     = inptr_local[1];
        outptr2[col]     = inptr_local[2];
        outptr0[col + 1] = inptr_local[4];
        outptr1[col + 1] = inptr_local[5];
        outptr2[col + 1] = inptr_local[6];
        inptr_local += 8;
    }
    // Handle remaining iteration if num_cols is odd
    if (col < num_cols) {
        outptr0[col] = inptr_local[0];
        outptr1[col] = inptr_local[1];
        outptr2[col] = inptr_local[2];
    }
}
