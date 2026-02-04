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
    for (col = 0; col < num_cols; col++) {
        JDIMENSION idx = col * 4;
        r = (inptr[idx + 2]);
        g = (inptr[idx + 1]);
        b = (inptr[idx + 0]);
        outptr0[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 << 8)] + ctab[b + (2 << 8)]) >> 16);
        outptr1[col] = (JSAMPLE)((ctab[r + (3 << 8)] + ctab[g + (4 << 8)] + ctab[b + (5 << 8)]) >> 16);
        outptr2[col] = (JSAMPLE)((ctab[r + (5 << 8)] + ctab[g + (6 << 8)] + ctab[b + (7 << 8)]) >> 16);
    }
}
