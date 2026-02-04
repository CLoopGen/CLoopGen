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
    JDIMENSION col;
    JSAMPROW local_inptr = inptr;
    JSAMPROW local_outptr = outptr;
    for (col = 0; col + 2 < num_cols; col += 3) {
        local_outptr[0] = local_inptr[0];
        local_outptr[1] = local_inptr[0];
        local_outptr[2] = local_inptr[0];
        local_outptr[3] = local_inptr[1];
        local_outptr[4] = local_inptr[1];
        local_outptr[5] = local_inptr[1];
        local_outptr[6] = local_inptr[2];
        local_outptr[7] = local_inptr[2];
        local_outptr[8] = local_inptr[2];
        local_inptr += 3;
        local_outptr += 9;
    }
    // Handle remaining elements
    for (; col < num_cols; col++) {
        local_outptr[0] = local_outptr[1] = local_outptr[2] = inptr[col];
        local_outptr += 3;
    }
}
