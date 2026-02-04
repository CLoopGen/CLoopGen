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
        r = 255 - ((int)(inptr[0]));
        g = 255 - ((int)(inptr[1]));
        b = 255 - ((int)(inptr[2]));
        outptr3[col] = inptr[3];
        outptr0[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (256))] + ctab[b + (2 * (256))]) >> 16);
        outptr1[col] = (JSAMPLE)((ctab[r + (3 * 256)] + ctab[g + (4 * 256)] + ctab[b + (5 * 256)]) >> 16);
        outptr2[col] = (JSAMPLE)((ctab[r + (5 * 256)] + ctab[g + (6 * 256)] + ctab[b + (7 * 256)]) >> 16);

        r = 255 - ((int)(inptr[4]));
        g = 255 - ((int)(inptr[5]));
        b = 255 - ((int)(inptr[6]));
        outptr3[col + 1] = inptr[7];
        outptr0[col + 1] = (JSAMPLE)((ctab[r + 0] + ctab[g + 256] + ctab[b + (2 * 256)]) >> 16);
        outptr1[col + 1] = (JSAMPLE)((ctab[r + (3 * 256)] + ctab[g + (4 * 256)] + ctab[b + (5 * 256)]) >> 16);
        outptr2[col + 1] = (JSAMPLE)((ctab[r + (5 * 256)] + ctab[g + (6 * 256)] + ctab[b + (7 * 256)]) >> 16);

        inptr += 8;
    } else {
        // Handle last pixel if num_cols is odd
        r = 255 - ((int)(inptr[0]));
        g = 255 - ((int)(inptr[1]));
        b = 255 - ((int)(inptr[2]));
        outptr3[col] = inptr[3];
        inptr += 4;
        outptr0[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + 256] + ctab[b + (2 * 256)]) >> 16);
        outptr1[col] = (JSAMPLE)((ctab[r + (3 * 256)] + ctab[g + (4 * 256)] + ctab[b + (5 * 256)]) >> 16);
        outptr2[col] = (JSAMPLE)((ctab[r + (5 * 256)] + ctab[g + (6 * 256)] + ctab[b + (7 * 256)]) >> 16);
    }
}
}
