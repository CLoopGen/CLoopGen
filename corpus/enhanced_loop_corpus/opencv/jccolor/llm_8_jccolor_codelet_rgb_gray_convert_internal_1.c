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
extern JSAMPROW outptr;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (col = 0; col < num_cols; col += 2) {
        if (col + 1 < num_cols) {
            r = inptr[0];
            g = inptr[1];
            b = inptr[2];
            int r2 = inptr[3];
            int g2 = inptr[4];
            int b2 = inptr[5];
            inptr += 6;
            JLONG val1 = ctab[r + 0] + ctab[g + (1 * (255 + 1))] + ctab[b + (2 * (255 + 1))];
            JLONG val2 = ctab[r2 + 0] + ctab[g2 + (1 * (255 + 1))] + ctab[b2 + (2 * (255 + 1))];
            outptr[col]     = (JSAMPLE)(val1 >> 16);
            outptr[col + 1] = (JSAMPLE)(val2 >> 16);
        } else {
            r = inptr[0];
            g = inptr[1];
            b = inptr[2];
            inptr += 3;
            outptr[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (255 + 1))] + ctab[b + (2 * (255 + 1))]) >> 16);
        }
    }
}
