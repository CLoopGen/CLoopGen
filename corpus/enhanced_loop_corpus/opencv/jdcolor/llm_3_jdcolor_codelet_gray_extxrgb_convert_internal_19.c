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
    // Variant 2: Strided memory access - write output with stride of 4 but process input in reverse order
    JDIMENSION idx = num_cols;
    JDIMENSION step = 1;
    JSAMPROW temp_out = outptr;
    while (idx--) {
        JDIMENSION rev_col = idx; // Reverse indexing
        temp_out[0*step] = 255;
        temp_out[1*step] = inptr[rev_col];
        temp_out[2*step] = inptr[rev_col];
        temp_out[3*step] = inptr[rev_col];
        temp_out += 4*step;
    }
    outptr = temp_out; // Maintain consistency with original side effect
}
