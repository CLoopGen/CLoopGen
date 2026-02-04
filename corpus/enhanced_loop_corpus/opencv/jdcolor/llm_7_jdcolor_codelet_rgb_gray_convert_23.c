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
extern JSAMPROW outptr;
extern JSAMPROW inptr0;
extern JSAMPROW inptr1;
extern JSAMPROW inptr2;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offset_g = 1 * (255 + 1);
    int offset_b = 2 * (255 + 1);
    JLONG accumulator = 0;
    for (col = 0; col < num_cols; col++) {
        r = inptr0[col];
        g = inptr1[col];
        b = inptr2[col];
        accumulator += ctab[r + 0] + ctab[g + offset_g] + ctab[b + offset_b];
        outptr[col] = (JSAMPLE)(accumulator >> 16);
        accumulator -= (ctab[r + 0] + ctab[g + offset_g] + ctab[b + offset_b]) >> 16;
    }
}
