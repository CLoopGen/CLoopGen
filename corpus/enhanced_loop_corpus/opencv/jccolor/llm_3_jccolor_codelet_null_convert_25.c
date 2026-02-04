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
    // Variant 2: Strided memory access - process multiple iterations at once with stride of 4
    JSAMPROW in = inptr;
    JDIMENSION stride = 4;
    for (col = 0; col < num_cols; col += 1) {
        // Access input as a linear array with incrementing index
        outptr0[col] = in[0];
        outptr1[col] = in[1];
        outptr2[col] = in[2];
        outptr3[col] = in[3];
        in += stride;
    }
    inptr = in; // Update external inptr to reflect advancement
}
