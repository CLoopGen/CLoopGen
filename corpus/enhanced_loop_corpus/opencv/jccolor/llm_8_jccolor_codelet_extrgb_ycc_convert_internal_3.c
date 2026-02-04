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
    for (col = 0; col < num_cols; col += 2) {
        if (col + 1 < num_cols) {
            // Process two pixels per iteration to increase computational intensity
            int r0 = inptr[0], g0 = inptr[1], b0 = inptr[2];
            int r1 = inptr[3], g1 = inptr[4], b1 = inptr[5];
            inptr += 6;

            outptr0[col]   = (JSAMPLE)((ctab[r0 + 0] + ctab[g0 + (1 * (255 + 1))] + ctab[b0 + (2 * (255 + 1))]) >> 16);
            outptr1[col]   = (JSAMPLE)((ctab[r0 + (3 * (255 + 1))] + ctab[g0 + (4 * (255 + 1))] + ctab[b0 + (5 * (255 + 1))]) >> 16);
            outptr2[col]   = (JSAMPLE)((ctab[r0 + (5 * (255 + 1))] + ctab[g0 + (6 * (255 + 1))] + ctab[b0 + (7 * (255 + 1))]) >> 16);

            outptr0[col+1] = (JSAMPLE)((ctab[r1 + 0] + ctab[g1 + (1 * (255 + 1))] + ctab[b1 + (2 * (255 + 1))]) >> 16);
            outptr1[col+1] = (JSAMPLE)((ctab[r1 + (3 * (255 + 1))] + ctab[g1 + (4 * (255 + 1))] + ctab[b1 + (5 * (255 + 1))]) >> 16);
            outptr2[col+1] = (JSAMPLE)((ctab[r1 + (5 * (255 + 1))] + ctab[g1 + (6 * (255 + 1))] + ctab[b1 + (7 * (255 + 1))]) >> 16);
        } else {
            // Handle last pixel if num_cols is odd
            r = inptr[0];
            g = inptr[1];
            b = inptr[2];
            inptr += 3;
            outptr0[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (255 + 1))] + ctab[b + (2 * (255 + 1))]) >> 16);
            outptr1[col] = (JSAMPLE)((ctab[r + (3 * (255 + 1))] + ctab[g + (4 * (255 + 1))] + ctab[b + (5 * (255 + 1))]) >> 16);
            outptr2[col] = (JSAMPLE)((ctab[r + (5 * (255 + 1))] + ctab[g + (6 * (255 + 1))] + ctab[b + (7 * (255 + 1))]) >> 16);
        }
    }
}
