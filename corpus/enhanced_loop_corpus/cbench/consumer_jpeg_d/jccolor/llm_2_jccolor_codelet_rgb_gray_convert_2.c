#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef unsigned int JDIMENSION;

extern int r;
extern int g;
extern int b;
extern INT32 *ctab;
extern JSAMPROW inptr;
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array indexing instead of pointer arithmetic
    for (col = 0; col < num_cols; col++) {
        r = ((int)(inptr[col * 3 + 0]));
        g = ((int)(inptr[col * 3 + 1]));
        b = ((int)(inptr[col * 3 + 2]));
        outptr[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (256))] + ctab[b + (2 * (256))]) >> 16);
    }
}
