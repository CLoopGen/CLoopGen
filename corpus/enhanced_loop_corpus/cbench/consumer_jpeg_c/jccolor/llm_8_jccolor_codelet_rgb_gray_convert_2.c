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
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < num_cols; col += 2) {
        if (col + 1 < num_cols) {
            r = ((int)(inptr[0]));
            g = ((int)(inptr[1]));
            b = ((int)(inptr[2]));
            inptr += 3;
            outptr[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (256))] + ctab[b + (2 * (256))]) >> 16);

            r = ((int)(inptr[0]));
            g = ((int)(inptr[1]));
            b = ((int)(inptr[2]));
            inptr += 3;
            outptr[col + 1] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (256))] + ctab[b + (2 * (256))]) >> 16);
        } else {
            r = ((int)(inptr[0]));
            g = ((int)(inptr[1]));
            b = ((int)(inptr[2]));
            inptr += 3;
            outptr[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (256))] + ctab[b + (2 * (256))]) >> 16);
        }
    }
}
