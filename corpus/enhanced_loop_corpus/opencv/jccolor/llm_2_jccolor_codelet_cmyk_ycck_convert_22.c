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
extern JSAMPROW outptr0;
extern JSAMPROW outptr1;
extern JSAMPROW outptr2;
extern JSAMPROW outptr3;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled for spatial locality
    JSAMPROW out0 = outptr0;
    JSAMPROW out1 = outptr1;
    JSAMPROW out2 = outptr2;
    JSAMPROW out3 = outptr3;
    JDIMENSION col4 = 0;
    for (col = 0; col < num_cols; col++, col4++) {
        r = 255 - inptr[0];
        g = 255 - inptr[1];
        b = 255 - inptr[2];
        out3[col4] = inptr[3];
        inptr += 4;
        *out0++ = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * 256)] + ctab[b + (2 * 256)]) >> 16);
        *out1++ = (JSAMPLE)((ctab[r + (3 * 256)] + ctab[g + (4 * 256)] + ctab[b + (5 * 256)]) >> 16);
        *out2++ = (JSAMPLE)((ctab[r + (6 * 256)] + ctab[g + (6 * 256)] + ctab[b + (7 * 256)]) >> 16);
    }
}
