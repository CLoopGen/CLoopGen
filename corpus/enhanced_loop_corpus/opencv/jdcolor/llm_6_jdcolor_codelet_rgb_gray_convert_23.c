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
    JLONG temp_r, temp_g, temp_b;
    for (col = 0; col < num_cols; col++) {
        r = inptr0[col];
        g = inptr1[col];
        b = inptr2[col];
        temp_r = ctab[r + 0];
        temp_g = ctab[g + (1 * (255 + 1))];
        temp_b = ctab[b + (2 * (255 + 1))];
        outptr[col] = (JSAMPLE)((temp_r + temp_g + temp_b) >> 16);
    }
}
