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
extern JSAMPROW outptr0;
extern JSAMPROW outptr1;
extern JSAMPROW outptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < num_cols; col += 2) {
        // Process two pixels per iteration to increase computational intensity
        int r0, g0, b0, r1, g1, b1;
        
        r0 = ((int)(inptr[0]));
        g0 = ((int)(inptr[1]));
        b0 = ((int)(inptr[2]));
        r1 = ((int)(inptr[3]));
        g1 = ((int)(inptr[4]));
        b1 = ((int)(inptr[5]));
        inptr += 6;

        // First pixel
        outptr0[col] = (JSAMPLE)((ctab[r0 + 0] + ctab[g0 + (1 * (256))] + ctab[b0 + (2 * (256))]) >> 16);
        outptr1[col] = (JSAMPLE)((ctab[r0 + (3 * (256))] + ctab[g0 + (4 * (256))] + ctab[b0 + (5 * (256))]) >> 16);
        outptr2[col] = (JSAMPLE)((ctab[r0 + (5 * (256))] + ctab[g0 + (6 * (256))] + ctab[b0 + (7 * (256))]) >> 16);

        // Second pixel (if within bounds)
        if (col + 1 < num_cols) {
            outptr0[col + 1] = (JSAMPLE)((ctab[r1 + 0] + ctab[g1 + (1 * (256))] + ctab[b1 + (2 * (256))]) >> 16);
            outptr1[col + 1] = (JSAMPLE)((ctab[r1 + (3 * (256))] + ctab[g1 + (4 * (256))] + ctab[b1 + (5 * (256))]) >> 16);
            outptr2[col + 1] = (JSAMPLE)((ctab[r1 + (5 * (256))] + ctab[g1 + (6 * (256))] + ctab[b1 + (7 * (256))]) >> 16);
        }
    }
}
