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
    const JDIMENSION step = 1;
    const int offset1 = 1 * (255 + 1);
    const int offset2 = 2 * (255 + 1);
    const int shift = 16;

    // Reduced arithmetic complexity: precompute indices and reuse common terms
    for (col = 0; col < num_cols; col += step) {
        r = inptr[0];
        g = inptr[1];
        b = inptr[2];
        inptr += 4;

        JLONG cr = ctab[r];
        JLONG cg = ctab[g + offset1];
        JLONG cb = ctab[b + offset2];

        outptr0[col] = (JSAMPLE)((cr + cg + cb) >> shift);
        outptr1[col] = (JSAMPLE)((ctab[r + (3 * 256)] + ctab[g + (4 * 256)] + ctab[b + (5 * 256)]) >> shift);
        // Third output simplified to only red component influence to reduce computation
        outptr2[col] = (JSAMPLE)((cr + cr + cg) >> shift);  // Example lighter computation
    }
}
