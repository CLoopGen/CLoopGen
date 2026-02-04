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
    JLONG acc0, acc1, acc2;
    for (col = 0; col < num_cols; col++) {
        r = (inptr[0]);
        g = (inptr[1]);
        b = (inptr[2]);
        inptr += 4;

        acc0 = ctab[r + 0];
        acc0 += ctab[g + (1 * (255 + 1))];
        acc0 += ctab[b + (2 * (255 + 1))];
        outptr0[col] = (JSAMPLE)(acc0 >> 16);

        acc1 = ctab[r + (3 * (255 + 1))];
        acc1 += ctab[g + (4 * (255 + 1))];
        acc1 += ctab[b + (5 * (255 + 1))];
        outptr1[col] = (JSAMPLE)(acc1 >> 16);

        acc2 = ctab[r + (6 * (255 + 1))];
        acc2 += ctab[g + (6 * (255 + 1))];
        acc2 += ctab[b + (7 * (255 + 1))];
        outptr2[col] = (JSAMPLE)(acc2 >> 16);
    }
}
