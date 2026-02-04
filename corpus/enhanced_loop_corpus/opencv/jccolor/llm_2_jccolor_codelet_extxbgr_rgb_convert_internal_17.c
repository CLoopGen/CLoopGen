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
    JDIMENSION col;
    JSAMPROW inptr_local = inptr;
    for (col = 0; col + 1 < num_cols; col += 2) {
        outptr0[col]     = inptr_local[3];
        outptr1[col]     = inptr_local[2];
        outptr2[col]     = inptr_local[1];
        
        outptr0[col + 1] = inptr_local[7];  // next pixel's B
        outptr1[col + 1] = inptr_local[6];  // next pixel's G
        outptr2[col + 1] = inptr_local[5];  // next pixel's R
        
        inptr_local += 8;  // advance by two pixels (8 bytes)
    }
    // Handle remaining element if num_cols is odd
    if (col < num_cols) {
        outptr0[col] = inptr_local[3];
        outptr1[col] = inptr_local[2];
        outptr2[col] = inptr_local[1];
    }
}
