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
            r = inptr[2];
            g = inptr[1];
            b = inptr[0];
            int r_next = inptr[6];
            int g_next = inptr[5];
            int b_next = inptr[4];
            inptr += 8;
            outptr[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (256))] + ctab[b + (2 * (256))]) >> 16);
            outptr[col + 1] = (JSAMPLE)((ctab[r_next + 0] + ctab[g_next + (1 * (256))] + ctab[b_next + (2 * (256))]) >> 16);
        } else {
            r = inptr[2];
            g = inptr[1];
            b = inptr[0];
            inptr += 4;
            outptr[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 * (256))] + ctab[b + (2 * (256))]) >> 16);
        }
    }
}
