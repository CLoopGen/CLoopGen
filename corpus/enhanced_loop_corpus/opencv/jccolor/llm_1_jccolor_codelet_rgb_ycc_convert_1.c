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
    if (num_cols > 0) {
        for (col = 0; col < num_cols; col += 2) {
            int col1 = col;
            int col2 = col + 1;
            r = ((int)(inptr[0]));
            g = ((int)(inptr[1]));
            b = ((int)(inptr[2]));
            inptr += 3;
            outptr0[col1] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * 256)] + ctab[b + (2 * 256)]) >> 16);
            outptr1[col1] = (JSAMPLE)((ctab[r + (3 * 256)] + ctab[g + (4 * 256)] + ctab[b + (5 * 256)]) >> 16);
            outptr2[col1] = (JSAMPLE)((ctab[r + (5 * 256)] + ctab[g + (6 * 256)] + ctab[b + (7 * 256)]) >> 16);

            if (col2 < num_cols) {
                r = ((int)(inptr[0]));
                g = ((int)(inptr[1]));
                b = ((int)(inptr[2]));
                inptr += 3;
                outptr0[col2] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * 256)] + ctab[b + (2 * 256)]) >> 16);
                outptr1[col2] = (JSAMPLE)((ctab[r + (3 * 256)] + ctab[g + (4 * 256)] + ctab[b + (5 * 256)]) >> 16);
                outptr2[col2] = (JSAMPLE)((ctab[r + (5 * 256)] + ctab[g + (6 * 256)] + ctab[b + (7 * 256)]) >> 16);
            }
        }
    }
}
