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
    JDIMENSION col_outer, col_inner;
    for (col_outer = 0; col_outer < num_cols; col_outer += 2) {
        for (col_inner = col_outer; col_inner < col_outer + 2 && col_inner < num_cols; col_inner++) {
            col = col_inner;
            r = (inptr[0]);
            g = (inptr[1]);
            b = (inptr[2]);
            inptr += 4;
            outptr0[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (255 + 1))] + ctab[b + (2 * (255 + 1))]) >> 16);
            outptr1[col] = (JSAMPLE)((ctab[r + (3 * (255 + 1))] + ctab[g + (4 * (255 + 1))] + ctab[b + (5 * (255 + 1))]) >> 16);
            outptr2[col] = (JSAMPLE)((ctab[r + (5 * (255 + 1))] + ctab[g + (6 * (255 + 1))] + ctab[b + (7 * (255 + 1))]) >> 16);
        }
    }
}
