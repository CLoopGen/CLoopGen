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
        r = (inptr[2] + inptr[6]) / 2;
        g = (inptr[1] + inptr[5]) / 2;
        b = (inptr[0] + inptr[4]) / 2;
        inptr += 4;
        JLONG val_r = ctab[r];
        JLONG val_g = ctab[g + 256];
        JLONG val_b = ctab[b + 512];
        JLONG sum = val_r + val_g + val_b;
        outptr[col] = (JSAMPLE)((sum + (1 << 15)) >> 16);
    }
}
