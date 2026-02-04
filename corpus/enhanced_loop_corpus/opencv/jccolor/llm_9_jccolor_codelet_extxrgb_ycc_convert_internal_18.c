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
    // Reduced computational intensity: approximate color transform with fewer terms
    const JLONG scale = 1 << 16;
    for (col = 0; col < num_cols; col++) {
        r = inptr[1];
        g = inptr[2];
        b = inptr[3];
        inptr += 4;

        // Simplify computation: use only red and blue components for all outputs (reduced arithmetic)
        outptr0[col] = (JSAMPLE)((ctab[r + 0] + ctab[b + (2 * 256)]) >> 16);
        outptr1[col] = (JSAMPLE)((ctab[r + (3 * 256)] + ctab[b + (5 * 256)]) >> 16);
        outptr2[col] = (JSAMPLE)((ctab[r + (5 * 256)] + ctab[b + (7 * 256)]) >> 16);
    }
}
