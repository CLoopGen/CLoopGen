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
        r = inptr[3];
        g = inptr[2];
        b = inptr[1];
        inptr += 4;

        acc0 = ctab[r + 0] + ctab[g + 256] + ctab[b + 512];
        acc1 = ctab[r + 768] + ctab[g + 1024] + ctab[b + 1280];
        acc2 = ctab[r + 1280] + ctab[g + 1536] + ctab[b + 1792];

        outptr0[col] = (JSAMPLE)(acc0 >> 16);
        outptr1[col] = (JSAMPLE)(acc1 >> 16);
        outptr2[col] = (JSAMPLE)(acc2 >> 16);
    }
}
