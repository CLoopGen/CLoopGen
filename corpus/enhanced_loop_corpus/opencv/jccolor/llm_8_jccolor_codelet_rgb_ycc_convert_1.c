#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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
    if (col + 1 < num_cols) {
        // Process two pixels per iteration to increase computational intensity
        r = ((int)(inptr[0]));
        g = ((int)(inptr[1]));
        b = ((int)(inptr[2]));
        int r_next = ((int)(inptr[3]));
        int g_next = ((int)(inptr[4]));
        int b_next = ((int)(inptr[5]));

        outptr0[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (256))] + ctab[b + (2 * (256))]) >> 16);
        outptr1[col] = (JSAMPLE)((ctab[r + (3 * (256))] + ctab[g + (4 * (256))] + ctab[b + (5 * (256))]) >> 16);
        outptr2[col] = (JSAMPLE)((ctab[r + (6 * (256))] + ctab[g + (7 * (256))] + ctab[b + (8 * (256))]) >> 16);

        outptr0[col + 1] = (JSAMPLE)((ctab[r_next + 0] + ctab[g_next + (1 * (256))] + ctab[b_next + (2 * (256))]) >> 16);
        outptr1[col + 1] = (JSAMPLE)((ctab[r_next + (3 * (256))] + ctab[g_next + (4 * (256))] + ctab[b_next + (5 * (256))]) >> 16);
        outptr2[col + 1] = (JSAMPLE)((ctab[r_next + (6 * (256))] + ctab[g_next + (7 * (256))] + ctab[b_next + (8 * (256))]) >> 16);

        inptr += 6;
    } else {
        // Handle leftover pixel
        r = ((int)(inptr[0]));
        g = ((int)(inptr[1]));
        b = ((int)(inptr[2]));
        inptr += 3;

        outptr0[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (256))] + ctab[b + (2 * (256))]) >> 16);
        outptr1[col] = (JSAMPLE)((ctab[r + (3 * (256))] + ctab[g + (4 * (256))] + ctab[b + (5 * (256))]) >> 16);
        outptr2[col] = (JSAMPLE)((ctab[r + (6 * (256))] + ctab[g + (7 * (256))] + ctab[b + (8 * (256))]) >> 16);
    }
}
}
