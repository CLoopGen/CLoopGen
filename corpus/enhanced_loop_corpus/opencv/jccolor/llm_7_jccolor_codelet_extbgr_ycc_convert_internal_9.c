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
        r = inptr[2];
        g = inptr[1];
        b = inptr[0];
        inptr += 3;

        acc0 = ctab[r + 0] + ctab[g + (1 * (256))] 
                    + ctab[b + (2 * (256))];
        acc1 = ctab[r + (3 * (256))] + ctab[g + (4 * (256))] 
                    + ctab[b + (5 * (256))];
        acc2 = ctab[r + (5 * (256))] + ctab[g + (6 * (256))] 
                    + ctab[b + (7 * (256))];

        outptr0[col] = (JSAMPLE)(acc0 >> 16);
        outptr1[col] = (JSAMPLE)(acc1 >> 16);
        outptr2[col] = (JSAMPLE)(acc2 >> 16);
    }
}
