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
extern JSAMPROW outptr3;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled in chunks
    JSAMPROW in = inptr;
    for (col = 0; col < num_cols; col++) {
        JSAMPLE val0 = *in++;
        JSAMPLE val1 = *in++;
        JSAMPLE val2 = *in++;
        JSAMPLE val3 = *in++;
        outptr0[col] = val0;
        outptr1[col] = val1;
        outptr2[col] = val2;
        outptr3[col] = val3;
    }
    inptr = in; // Update original inptr if needed
}
