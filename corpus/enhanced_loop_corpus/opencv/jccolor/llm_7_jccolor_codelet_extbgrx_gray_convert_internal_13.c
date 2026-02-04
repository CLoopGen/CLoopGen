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
    int offset = 0;
    for (col = 0; col < num_cols; col++) {
        r = inptr[offset + 2];
        g = inptr[offset + 1];
        b = inptr[offset + 0];
        offset += 4;
        outptr[col] = (JSAMPLE)((ctab[r] + ctab[g + 256] + ctab[b + 512]) >> 16);
    }
    inptr += offset; // Update inptr after loop (introduces WAW dependency elimination and loop-carried dependency change)
}
