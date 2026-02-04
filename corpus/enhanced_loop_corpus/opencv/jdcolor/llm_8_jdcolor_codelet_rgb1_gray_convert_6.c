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
extern INT32 y;
extern INT32 *Rytab;
extern INT32 *Gytab;
extern INT32 *Bytab;
extern JSAMPROW outptr;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JDIMENSION col;
    for (col = 0; col < num_cols; col += 2) {
        if (col + 1 < num_cols) {
            int r0 = ((int)(inptr0[col]));
            int g0 = ((int)(inptr1[col]));
            int b0 = ((int)(inptr2[col]));
            int r1 = ((int)(inptr0[col + 1]));
            int g1 = ((int)(inptr1[col + 1]));
            int b1 = ((int)(inptr2[col + 1]));

            INT32 y0 = Rytab[(r0 + g0 - 128) & 255];
            y0 += Gytab[g0];
            y0 += Bytab[(b0 + g0 - 128) & 255];
            outptr[col] = (JSAMPLE)(y0 >> 16);

            INT32 y1 = Rytab[(r1 + g1 - 128) & 255];
            y1 += Gytab[g1];
            y1 += Bytab[(b1 + g1 - 128) & 255];
            outptr[col + 1] = (JSAMPLE)(y1 >> 16);
        } else {
            r = ((int)(inptr0[col]));
            g = ((int)(inptr1[col]));
            b = ((int)(inptr2[col]));
            y = Rytab[(r + g - 128) & 255];
            y += Gytab[g];
            y += Bytab[(b + g - 128) & 255];
            outptr[col] = (JSAMPLE)(y >> 16);
        }
    }
}
