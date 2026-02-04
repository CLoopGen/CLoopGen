#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern int r;
extern int g;
extern int b;
extern JLONG *ctab;
extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - process every second pixel, then fill in reverse order
    // This changes access pattern to non-consecutive and reverses output storage
    JDIMENSION stride = 2;
    JDIMENSION half_cols = num_cols / stride;

    // First pass: process even-indexed pixels (0, 2, 4, ...)
    for (col = 0; col < half_cols; col++) {
        r = inptr[col * stride * 4 + 0];
        g = inptr[col * stride * 4 + 1];
        b = inptr[col * stride * 4 + 2];
        outptr[num_cols - 1 - col] = (JSAMPLE)((ctab[r + 0] + ctab[g + 256] + ctab[b + 512]) >> 16);
    }

    // Second pass: process odd-indexed pixels (1, 3, 5, ...) if any remain
    for (col = 0; col < half_cols && (col * stride + 1) < num_cols; col++) {
        r = inptr[(col * stride + 1) * 4 + 0];
        g = inptr[(col * stride + 1) * 4 + 1];
        b = inptr[(col * stride + 1) * 4 + 2];
        outptr[half_cols - 1 - col] = (JSAMPLE)((ctab[r + 0] + ctab[g + 256] + ctab[b + 512]) >> 16);
    }
}
