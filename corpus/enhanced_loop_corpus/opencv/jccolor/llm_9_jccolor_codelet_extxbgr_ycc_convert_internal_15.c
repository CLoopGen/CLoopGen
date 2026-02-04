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
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int shift = 16;
    const int stride = 256;
    JLONG sum0, sum1, sum2;

    for (col = 0; col < num_cols; col++) {
        r = inptr[3];
        g = inptr[2];
        b = inptr[1];
        inptr += 4;

        // Reduce arithmetic operations by precomputing base offsets (but keep same logic)
        sum0 = ctab[r] + ctab[g + stride] + ctab[b + (2 * stride)];
        sum1 = ctab[r + (3 * stride)] + ctab[g + (4 * stride)] + ctab[b + (5 * stride)];
        sum2 = ctab[r + (5 * stride)] + ctab[g + (6 * stride)] + ctab[b + (7 * stride)];

        outptr0[col] = (JSAMPLE)(sum0 >> shift);
        outptr1[col] = (JSAMPLE)(sum1 >> shift);
        outptr2[col] = (JSAMPLE)(sum2 >> shift);
    }
}
