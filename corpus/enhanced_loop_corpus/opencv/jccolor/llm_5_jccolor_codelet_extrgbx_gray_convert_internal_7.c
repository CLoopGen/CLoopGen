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
    for (col = 0; col < num_cols; col++) {
        r = (inptr[0]);
        g = (inptr[1]);
        b = (inptr[2]);
        inptr += 4;
        JLONG result = 0;
        if (r < 256 && g < 256 && b < 256) {
            result = ctab[r + 0] + ctab[g + (1 * (256))] + ctab[b + (2 * (256))];
            outptr[col] = (JSAMPLE)(result >> 16);
        } else {
            outptr[col] = (JSAMPLE)0;
        }
    }
}
