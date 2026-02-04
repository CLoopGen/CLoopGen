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



void loop() {
    for (col = 0; col < num_cols; col++) {
        r = inptr[col * 4 + 0];
        g = inptr[col * 4 + 1];
        b = inptr[col * 4 + 2];
        outptr0[col] = (JSAMPLE)((ctab[r + 0] + ctab[g + (1 << 9)] + ctab[b + (2 << 9)]) >> 16);
        outptr1[col] = (JSAMPLE)((ctab[r + (3 << 9)] + ctab[g + (4 << 9)] + ctab[b + (5 << 9)]) >> 16);
        outptr2[col] = (JSAMPLE)((ctab[r + (5 << 9)] + ctab[g + (6 << 9)] + ctab[b + (7 << 9)]) >> 16);
    }
}
