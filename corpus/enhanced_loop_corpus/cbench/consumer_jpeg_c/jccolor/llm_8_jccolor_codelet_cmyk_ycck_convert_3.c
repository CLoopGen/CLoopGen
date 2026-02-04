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
extern JSAMPROW outptr3;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (col = 0; col < num_cols; col += 2) {
    if (col + 1 < num_cols) {
        // Process two pixels per iteration to increase computational intensity
        int r0 = 255 - ((int)(inptr[0]));
        int g0 = 255 - ((int)(inptr[1]));
        int b0 = 255 - ((int)(inptr[2]));
        int r1 = 255 - ((int)(inptr[4]));
        int g1 = 255 - ((int)(inptr[5]));
        int b1 = 255 - ((int)(inptr[6]));

        outptr3[col] = inptr[3];
        outptr3[col+1] = inptr[7];

        outptr0[col] = (JSAMPLE)((ctab[r0 + 0] + ctab[g0 + (1 * (255 + 1))] + ctab[b0 + (2 * (255 + 1))]) >> 16);
        outptr0[col+1] = (JSAMPLE)((ctab[r1 + 0] + ctab[g1 + (1 * (255 + 1))] + ctab[b1 + (2 * (255 + 1))]) >> 16);

        outptr1[col] = (JSAMPLE)((ctab[r0 + (3 * (255 + 1))] + ctab[g0 + (4 * (255 + 1))] + ctab[b0 + (5 * (255 + 1))]) >> 16);
        outptr1[col+1] = (JSAMPLE)((ctab[r1 + (3 * (255 + 1))] + ctab[g1 + (4 * (255 + 1))] + ctab[b1 + (5 * (255 + 1))]) >> 16);

        outptr2[col] = (JSAMPLE)((ctab[r0 + (5 * (255 + 1))] + ctab[g0 + (6 * (255 + 1))] + ctab[b0 + (7 * (255 + 1))]) >> 16);
        outptr2[col+1] = (JSAMPLE)((ctab[r1 + (5 * (255 + 1))] + ctab[g1 + (6 * (255 + 1))] + ctab[b1 + (7 * (255 + 1))]) >> 16);

        inptr += 8;
    } else {
        // Handle last pixel if num_cols is odd
        r = 255 - ((int)(inptr[0]));
        g = 255 - ((int)(inptr[1]));
        b = 255 - ((int)(inptr[2]));
        outptr3[col] = inptr[3];
        inptr += 4;
        outptr0[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (255 + 1))] + ctab[b + (2 * (255 + 1))]) >> 16);
        outptr1[col] = (JSAMPLE)((ctab[r + (3 * (255 + 1))] + ctab[g + (4 * (255 + 1))] + ctab[b + (5 * (255 + 1))]) >> 16);
        outptr2[col] = (JSAMPLE)((ctab[r + (5 * (255 + 1))] + ctab[g + (6 * (255 + 1))] + ctab[b + (7 * (255 + 1))]) >> 16);
    }
}
}
