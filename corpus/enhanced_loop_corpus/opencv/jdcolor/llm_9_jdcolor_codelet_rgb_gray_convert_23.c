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
    for (col = 0; col < num_cols && col < 64; col++) {
        r = inptr0[col] * 2;
        g = inptr1[col] * 2;
        b = inptr2[col] * 2;
        JLONG val_r = ctab[r + 0] >> 8;
        JLONG val_g = ctab[g + 256] >> 8;
        JLONG val_b = ctab[b + 512] >> 8;
        JLONG sum = (val_r + val_g + val_b) >> 8;
        outptr[col] = (JSAMPLE)(sum >> 8);
    }
}
