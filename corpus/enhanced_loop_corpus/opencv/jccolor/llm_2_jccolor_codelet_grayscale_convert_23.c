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
extern int instride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling by 2
    JDIMENSION col;
    JSAMPROW inptr_local = inptr;
    for (col = 0; col + 1 < num_cols; col += 2) {
        outptr[col] = inptr_local[0];
        outptr[col + 1] = inptr_local[instride];
        inptr_local += 2 * instride;
    }
    // Handle remaining element if num_cols is odd
    if (col < num_cols) {
        outptr[col] = inptr_local[0];
    }
}
