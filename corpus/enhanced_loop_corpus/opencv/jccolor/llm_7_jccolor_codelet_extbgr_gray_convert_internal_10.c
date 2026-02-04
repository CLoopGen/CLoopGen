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
    JLONG accumulator = 0;
    for (col = 0; col < num_cols; col++) {
        r = inptr[2];
        g = inptr[1];
        b = inptr[0];
        accumulator = ctab[r + 0];
        accumulator += ctab[g + (1 * (255 + 1))];
        accumulator += ctab[b + (2 * (255 + 1))];
        inptr += 3;
        outptr[col] = (JSAMPLE)(accumulator >> 16);
        accumulator = 0; // Eliminate loop-carried dependency by resetting
    }
}
