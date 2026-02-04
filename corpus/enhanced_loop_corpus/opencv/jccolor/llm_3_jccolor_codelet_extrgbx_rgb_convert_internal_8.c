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
    // Variant 2: Strided memory access - process every second column first, then fill gaps
    JDIMENSION col;
    JSAMPROW inptr_even = inptr;
    JSAMPROW inptr_odd = inptr + 4;

    // Process even indices
    for (col = 0; col < num_cols; col += 2) {
        outptr0[col] = inptr_even[0];
        outptr1[col] = inptr_even[1];
        outptr2[col] = inptr_even[2];
        inptr_even += 8;
    }

    // Process odd indices
    for (col = 1; col < num_cols; col += 2) {
        outptr0[col] = inptr_odd[0];
        outptr1[col] = inptr_odd[1];
        outptr2[col] = inptr_odd[2];
        inptr_odd += 8;
    }
}
