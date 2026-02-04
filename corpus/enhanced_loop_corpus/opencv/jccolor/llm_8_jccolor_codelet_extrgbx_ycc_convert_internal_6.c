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
            r = inptr[0];
            g = inptr[1];
            b = inptr[2];
            int r2 = inptr[4];
            int g2 = inptr[5];
            int b2 = inptr[6];
            inptr += 8;

            // First pixel
            outptr0[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * 256)] + ctab[b + (2 * 256)]) >> 16);
            outptr1[col] = (JSAMPLE)((ctab[r + (3 * 256)] + ctab[g + (4 * 256)] + ctab[b + (5 * 256)]) >> 16);
            outptr2[col] = (JSAMPLE)((ctab[r + (6 * 256)] + ctab[g + (7 * 256)] + ctab[b + (8 * 256)]) >> 16);

            // Second pixel
            outptr0[col + 1] = (JSAMPLE)((ctab[r2 + 0] + ctab[g2 + (1 * 256)] + ctab[b2 + (2 * 256)]) >> 16);
            outptr1[col + 1] = (JSAMPLE)((ctab[r2 + (3 * 256)] + ctab[g2 + (4 * 256)] + ctab[b2 + (5 * 256)]) >> 16);
            outptr2[col + 1] = (JSAMPLE)((ctab[r2 + (6 * 256)] + ctab[g2 + (7 * 256)] + ctab[b2 + (8 * 256)]) >> 16);
        } else {
            // Handle odd-sized row end
            r = inptr[0];
            g = inptr[1];
            b = inptr[2];
            inptr += 4;
            outptr0[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * 256)] + ctab[b + (2 * 256)]) >> 16);
            outptr1[col] = (JSAMPLE)((ctab[r + (3 * 256)] + ctab[g + (4 * 256)] + ctab[b + (5 * 256)]) >> 16);
            outptr2[col] = (JSAMPLE)((ctab[r + (6 * 256)] + ctab[g + (7 * 256)] + ctab[b + (8 * 256)]) >> 16);
        }
    }
}
