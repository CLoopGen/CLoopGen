#include <stdio.h>

#include <inttypes.h>

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
    // Variant 2: Strided output access with reversed input traversal
    JDIMENSION col;
    JSAMPROW inptr_temp = inptr + (num_cols - 1) * instride;
    for (col = 0; col < num_cols; col++) {
        outptr[col * instride] = inptr_temp[0];  // Output written with stride
        inptr_temp -= instride;  // Traverse input backwards
    }
}
