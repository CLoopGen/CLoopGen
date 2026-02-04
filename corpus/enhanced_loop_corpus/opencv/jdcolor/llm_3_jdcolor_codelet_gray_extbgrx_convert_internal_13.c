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



void loop() {
    // Variant 2: Strided memory access - process every 2nd element first, then fill gaps
    JSAMPROW inptr_local = inptr;
    JSAMPROW outptr_local = outptr;
    JDIMENSION stride = 2;

    // First pass: even indices (strided access)
    for (col = 0; col < num_cols; col += stride) {
        JSAMPLE val = inptr_local[col];
        outptr_local[0] = val;
        outptr_local[1] = val;
        outptr_local[2] = val;
        outptr_local[3] = 255;
        outptr_local += 4;
    }

    // Second pass: odd indices (strided access starting at 1)
    for (col = 1; col < num_cols; col += stride) {
        JSAMPLE val = inptr_local[col];
        outptr_local[0] = val;
        outptr_local[1] = val;
        outptr_local[2] = val;
        outptr_local[3] = 255;
        outptr_local += 4;
    }
}
