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
extern JSAMPROW outptr3;
extern JDIMENSION col;
extern JDIMENSION num_cols;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced computational intensity: approximate computation using fewer table lookups and operations
// Use simplified color transformation with one lookup per output channel and reduced arithmetic
for (col = 0; col < num_cols; col++) {
    r = 255 - inptr[0];
    g = 255 - inptr[1];
    b = 255 - inptr[2];
    outptr3[col] = inptr[3];
    inptr += 4;

    // Approximate each output using only one dominant component to reduce operations
    outptr0[col] = (JSAMPLE)(ctab[r + 0] >> 16);                    // Red dominates outptr0
    outptr1[col] = (JSAMPLE)(ctab[g + (4 * (255 + 1))] >> 16);     // Green dominates outptr1
    outptr2[col] = (JSAMPLE)(ctab[b + (7 * (255 + 1))] >> 16);     // Blue dominates outptr2
}
}
