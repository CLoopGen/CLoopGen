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



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling
    JDIMENSION col4;
    JSAMPROW outptr_local = outptr;
    JSAMPROW inptr_local = inptr;

    // Process 4 elements at a time for consecutive write pattern
    for (col = 0, col4 = 0; col4 < num_cols / 4 * 4; col4 += 4) {
        outptr_local[0] = outptr_local[1] = outptr_local[2] = inptr_local[col4];
        outptr_local[3] = outptr_local[4] = outptr_local[5] = inptr_local[col4 + 1];
        outptr_local[6] = outptr_local[7] = outptr_local[8] = inptr_local[col4 + 2];
        outptr_local[9] = outptr_local[10] = outptr_local[11] = inptr_local[col4 + 3];
        outptr_local += 12;
    }
    // Handle remaining elements
    for (col = col4; col < num_cols; col++) {
        outptr_local[0] = outptr_local[1] = outptr_local[2] = inptr_local[col];
        outptr_local += 3;
    }
}
