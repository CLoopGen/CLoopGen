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
        int idx = col * 3;
        r = inptr[idx + 0];
        g = inptr[idx + 1];
        b = inptr[idx + 2];

        JLONG sum0 = ctab[r + 0];
        JLONG sum1 = ctab[r + (3 * 256)];
        JLONG sum2 = ctab[r + (5 * 256)];

        sum0 += ctab[g + (1 * 256)];
        sum1 += ctab[g + (4 * 256)];
        sum2 += ctab[g + (6 * 256)];

        sum0 += ctab[b + (2 * 256)];
        sum1 += ctab[b + (5 * 256)];
        sum2 += ctab[b + (7 * 256)];

        outptr0[col] = (JSAMPLE)(sum0 >> 16);
        outptr1[col] = (JSAMPLE)(sum1 >> 16);
        outptr2[col] = (JSAMPLE)(sum2 >> 16);
    }
}
