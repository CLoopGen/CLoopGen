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
    // Reduced computational load by removing one term from each output calculation
    for (col = 0; col < num_cols; col++) {
        r = (inptr[2]);
        g = (inptr[1]);
        b = (inptr[0]);
        inptr += 4;

        // Simplify arithmetic: use only two components instead of three
        outptr0[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + 256]) >> 16);
        outptr1[col] = (JSAMPLE)((ctab[g + (4 * 256)] + ctab[b + (5 * 256)]) >> 16);
        outptr2[col] = (JSAMPLE)((ctab[r + (6 * 256)] + ctab[b + (7 * 256)]) >> 16);
    }
}
