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
    // Variant 2: Strided output access with reversed iteration order
    JDIMENSION col;
    JSAMPROW inptr_local = inptr + (num_cols - 1) * instride;
    for (col = num_cols; col > 0; --col) {
        outptr[(num_cols - col) * 2] = inptr_local[0];  // Write to even indices only (strided write)
        inptr_local -= instride;
    }
}
