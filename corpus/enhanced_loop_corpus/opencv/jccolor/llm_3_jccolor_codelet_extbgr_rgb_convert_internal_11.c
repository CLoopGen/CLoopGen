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
    // Variant 2: Strided memory access - process every 4th column to simulate tiling or subsampling pattern
    const JDIMENSION stride = 4;
    JDIMENSION limit = (num_cols + stride - 1) / stride;  // ceil(num_cols / stride)

    for (col = 0; col < limit; col++) {
        JDIMENSION idx = col * stride;
        if (idx < num_cols) {
            outptr0[idx] = inptr[2];
            outptr1[idx] = inptr[1];
            outptr2[idx] = inptr[0];
        }
        inptr += 3;
    }
}
